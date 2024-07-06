//%attributes = {}
/*
 Method: OWA_checkUserCredentials   ( ) ->
 By: MelvinBohince @ 07/05/24, 00:19:07
 Description:
    Allow for credentials to be check for specific endpoints

    Testing using "Basic" Authorization mode for ELC Ariba, so user and password Base64 encoded 
     from Postman for testing

 Example Use:
  $accessGranted:=OWA_checkUserCredentials("ELCAriba")
*/

#DECLARE($endPointRequested : Text)->$accessGranted : Boolean

var $webUser_e : cs:C1710.Web_UsersEntity
var $authorizationValue : Text
//testing vars:
var $allowedAuthentications_c : Collection
var $encodedUser : Text
var $NOT_FOUND : Integer

If (Count parameters:C259=0)  //testing
	$endPointRequested:="ELCAriba"
	BASE64 ENCODE:C895("ELC Ariba User:xxx"; $encodedUser)
	$authorizationValue:="Basic "+$encodedUser
	
Else 
	//get the authorization header and its value
	ARRAY TEXT:C222($httpHeaderNames_at; 0)
	ARRAY TEXT:C222($httpHeaderValues_at; 0)
	
	WEB GET HTTP HEADER:C697($httpHeaderNames_at; $httpHeaderValues_at)
	$authorizationValue:=$httpHeaderValues_at{Find in array:C230($httpHeaderNames_at; "Authorization")}
End if 

$accessGranted:=True:C214

//prototype hardcodes encoded username and password for BASIC Authentication, but could be a query:
$webUser_e:=ds:C1482.Web_Users.query("EndPoint = :1 and BasicAuthentication = :2"; $endPointRequested; $authorizationValue).first()
If ($webUser_e#Null:C1517)
	return $accessGranted
	
Else   //use hard coded list
	
	$allowedAuthentications_c:=New collection:C1472
	$NOT_FOUND:=-1
	
	BASE64 ENCODE:C895("ELC Ariba User:xxx"; $encodedUser)
	$allowedAuthentications_c.push("Basic "+$encodedUser)
	
	BASE64 ENCODE:C895("demo:demo"; $encodedUser)
	$allowedAuthentications_c.push("Basic "+$encodedUser)
	
	If ($allowedAuthentications_c.indexOf($authorizationValue)=$NOT_FOUND)
		$accessGranted:=False:C215
		
	Else 
		$accessGranted:=True:C214
	End if 
	
	return $accessGranted
End if 
