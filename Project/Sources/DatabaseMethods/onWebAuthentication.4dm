/*
 Method: 00_OWA   ( ) ->
 By: MelvinBohince @ 07/03/24, 21:18:48
 Description:
  The On Web Authentication database method is in charge of 
     managing web server engine access. It is called by 4D or 
     4D Server when a dynamic HTTP request is received.

  Not called when the web server reveives a URL beginning with 
     rest/ and the REST server is launched (in this case, the 
     authentication is handled through the On REST Authentication 
     database method or Structure settings).

  Current implementation checks the client's ip against a white list and the
     requestors username and password

*/

// from https://developer.4d.com/docs/WebServer/authentication#on-web-authentication
#DECLARE($url : Text; $header : Text; \
$ipClient : Text; $ipServer : Text; \
$user : Text; $password : Text)\
->$accessGranted : Boolean

var $denied : Boolean  //just for readability rather than setting $accessGranted to false

$accessGranted:=True:C214  //must answer the riddle first my precious
$denied:=False:C215

//mark:Allow for route specific authentications in the caseof structure below

Case of 
		
		//mark:-.    ELC Project Synphony and cXML
	: (Position:C15("ELCAriba"; $url)>0)
		
		$accessGranted:=OWA_checkClientWhiteList($ipClient; "ELCAriba")
		If (Not:C34($accessGranted))
			return $denied
		End if 
		
		$accessGranted:=OWA_checkUserCredentials("ELCAriba")
		If (Not:C34($accessGranted))
			return $denied
		End if 
		
		//mark:.        !!! Access granted !!!
		return $accessGranted
		
		
		//mark:-.    Some future routing that is permitted
	: (Position:C15("Rollstock_Scanner_url"; $url)>0)  //some_future_url
		//not implemented
		
		//mark:.    Else an unrecognized route requested, fail silently
	Else 
		return $denied
End case 
