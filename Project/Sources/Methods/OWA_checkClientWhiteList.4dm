//%attributes = {}
/*
 Method: OWA_checkClientWhiteList   ( ) ->
 By: MelvinBohince @ 07/05/24, 00:03:40
 Description:
  Check if the client's ip is known to be valid,
    ideally the client has been set up in Trading_Partners
    see method _migrations; if not, a run-time collection is used

 Example Use:
  $accessGranted:=OWA_checkClientWhiteList($ipClient; "ELCAriba")
*/

#DECLARE($ipClient : Text; $endPointRequested : Text)->$accessGranted : Boolean

var $tradingPartner_e : cs:C1710.Trading_PartnersEntity
var $allowedClientIPs_c : Collection  //white list of ip's
var $NOT_FOUND : Integer:=-1
var $PERMITTED : Boolean:=True:C214
var $DENIED : Boolean:=False:C215

If (Count parameters:C259=0)  //testing
	$ipClient:="1.1.1.1"  //fails
	$endPointRequested:="ELCAriba"
End if 

$accessGranted:=$PERMITTED

//see if client's IP has been registered for this endpoint
$tradingPartner_e:=ds:C1482.Trading_Partners.query("RegisteredIP = :1 and EndPoint = :2"; $ipClient; $endPointRequested).first()
If ($tradingPartner_e#Null:C1517)
	return $accessGranted
	
Else   //use hard coded list
	
	$allowedClientIPs_c:=New collection:C1472
	Case of 
		: ($endPointRequested="ELCAriba")  //testing
			$allowedClientIPs_c.push("127.0.0.1")  //local host
			$allowedClientIPs_c.push("10.0.0.162")
			$allowedClientIPs_c.push("192.168.1.51")
			$allowedClientIPs_c.push("130.214.184.67")  //ELC test client
			
		Else   //extend endpoints as necessary
			
	End case 
	
	If ($allowedClientIPs_c.indexOf($ipClient)=$NOT_FOUND)
		$accessGranted:=$DENIED
		
	Else 
		$accessGranted:=$PERMITTED
	End if 
	
	return $accessGranted
	
End if   //using hardcoded list
