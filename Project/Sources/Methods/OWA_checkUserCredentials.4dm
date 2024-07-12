//%attributes = {}
/*
 Method: OWA_checkUserCredentials   ( ) ->
 By: MelvinBohince @ 07/05/24, 00:19:07
 Description:
    Allow for credentials to be check for specific endpoints. Ideally 
      the client has been set up in Web_Users
      see method _migrations; if not, a run-time collection is used

    Testing using "Basic" Authorization mode for ELC Ariba, so user and password Base64 encoded 
     from Postman for testing and extracted from the POST's headers

 Example Use:
  $accessGranted:=OWA_checkUserCredentials("ELCAriba")
*/

#DECLARE($endPointRequested : Text)->$accessGranted : Boolean

var $webUser_e : cs:C1710.Web_UsersEntity
var $authorizationValue : Text
//testing vars:
var $allowedAuthentications_c : Collection
var $encodedUser : Text
var $NOT_FOUND : Integer:=-1
var $PERMITTED : Boolean:=True:C214
var $DENIED : Boolean:=False:C215

If (Count parameters:C259=0)  //testing
	$endPointRequested:="ELCAriba"
	BASE64 ENCODE:C895("ELC Ariba User:xxx"; $encodedUser)
	$authorizationValue:="Basic "+$encodedUser
	
Else 
	//get the authorization header's value
	$authorizationValue:=Session:C1714.storage.header_o["Authorization"]
End if 

$accessGranted:=$PERMITTED

//prototype hardcodes encoded username and password for BASIC Authentication, but could be a query:
$webUser_e:=ds:C1482.Web_Users.query("EndPoint = :1 and BasicAuthentication = :2"; $endPointRequested; $authorizationValue).first()
If ($webUser_e#Null:C1517)
	return $accessGranted
	
Else   //use hard coded list
	
	$allowedAuthentications_c:=New collection:C1472
	
	BASE64 ENCODE:C895("ELC Ariba User:xxx"; $encodedUser)
	$allowedAuthentications_c.push("Basic "+$encodedUser)
	
	BASE64 ENCODE:C895("demo:demo"; $encodedUser)
	$allowedAuthentications_c.push("Basic "+$encodedUser)
	
	If ($allowedAuthentications_c.indexOf($authorizationValue)=$NOT_FOUND)
		$accessGranted:=$DENIED
		
	Else 
		$accessGranted:=$PERMITTED
	End if 
	
	return $accessGranted
End if 
