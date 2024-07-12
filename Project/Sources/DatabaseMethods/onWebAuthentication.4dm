/*
 Method: Method: On Web Authentication ( ) ->
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

/*
tested from terminal with:
 curl -X POST -u "ELC Ariba User":xxx -H "Content-Type:text/xml; charset=UTF-8" -H "Content-Length:15466" --data-binary @/Users/mel/Desktop/00-elc-samples/00-cXML_PO_elc.txt  http://127.0.0.1:8080/ELCAriba/   
*/

// from https://developer.4d.com/docs/WebServer/authentication#on-web-authentication
#DECLARE($url : Text; $header : Text; \
$ipClient : Text; $ipServer : Text; \
$user : Text; $password : Text)\
->$accessGranted : Boolean

var $ACCESS_DENIED : Boolean:=False:C215  //just for readability rather than setting $accessGranted to false
var $header_o : Object  //header arrays packed into dictionary object and placed into Session.storage
var $response_o : Object  //will be placed into Session.storage

$header_o:=OWC_initHeaderObject

$response_o:=OWC_initResponseObject("202 Accepted")

$accessGranted:=False:C215  //must answer the riddle first my precious

//mark:Allow for route specific authentications in the caseof structure below

Case of 
		
		//mark:-.    ELC Project Synphony and cXML
	: (Position:C15("ELCAriba"; $url)>0)
		
		$accessGranted:=OWA_checkClientWhiteList($ipClient; "ELCAriba")
		If (Not:C34($accessGranted))
			$result_t:=OWC_setResponse("403 Forbidden")
			$result_t:=OWC_sendResponse
			return $ACCESS_DENIED
		End if 
		
		$accessGranted:=OWA_checkUserCredentials("ELCAriba")
		If (Not:C34($accessGranted))
			$result_t:=OWC_setResponse("401 Unauthorized")
			$result_t:=OWC_sendResponse
			return $ACCESS_DENIED
		End if 
		
		//mark:-.    Some future routing that is permitted
	: (Position:C15("Rollstock_Scanner_url"; $url)>0)  //some_future_url
		//not implemented
		$result_t:=OWC_setResponse("404 Not Found")
		$result_t:=OWC_sendResponse
		return $ACCESS_DENIED
		
	Else   //Else an unrecognized route requested
		$result_t:=OWC_setResponse("418 I'm a teapot")
		$result_t:=OWC_sendResponse
		return $ACCESS_DENIED
End case 

//mark:.    riddles answered !!! Access granted !!!
return $accessGranted  //continue on to On Web Connection
