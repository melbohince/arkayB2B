//%attributes = {}
/*
 Method: OWA_checkClientWhiteList   ( ) ->
 By: MelvinBohince @ 07/05/24, 00:03:40
 Description:
  Check if the client's ip is known to be valid

 Example Use:
  $accessGranted:=OWA_checkClientWhiteList($ipClient; "ELCAriba")
*/

#DECLARE($ipClient : Text; $endPointRequested : Text)->$accessGranted : Boolean

var $allowedClientIPs_c : Collection  //white list of ip's
var $NOT_FOUND : Integer

$allowedClientIPs_c:=New collection:C1472
$NOT_FOUND:=-1

//prototype using a case stmt, but could build the collection from ip's saved in a table keyed by endpoint
//$allowedClientIPs_c:=ds.ClientWhiteList.query("client = :1 and endPoint = :2";$ipClient;$endPointRequested).distinct("knownIPs")

Case of 
	: ($endPointRequested="ELCAriba")
		$allowedClientIPs_c.push("127.0.0.1")  //local host
		$allowedClientIPs_c.push("10.0.0.162")
		$allowedClientIPs_c.push("192.168.1.51")
		$allowedClientIPs_c.push("130.214.184.67")  //ELC test client
		
	Else   //extend as necessary
		
End case 

If ($allowedClientIPs_c.indexOf($ipClient)=$NOT_FOUND)
	$accessGranted:=False:C215
	
Else 
	$accessGranted:=True:C214
End if 

return $accessGranted
