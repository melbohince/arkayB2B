/*
 Method: On Web Connection    ( ) ->
 By: MelvinBohince @ 07/03/24, 20:48:31
 Description:
  The request has previously been accepted by the 
    On Web Authentication database method returning true.

  The On Web Connection database method is automatically called  
    when the server reveives any URL that is not a path to an 
    existing page on the server. The database method is called 
    with the URL.

*/

// from https://developer.4d.com/docs/WebServer/httpRequests/#on-web-connection
#DECLARE($url : Text; $header : Text; \
$ipClient : Text; $ipServer : Text; \
$user : Text; $password : Text)

var $header_o : Object  //header arrays packed into dictionary object
var $response_o : Object  //will be placed into Session.storage
var $result_t : Text

$header_o:=OWC_initHeaderObject

$response_o:=OWC_initResponseObject("200 OK")

//mark:-Decide what route a client is looking for

Case of 
		
		//mark:-.    ELC Project Symphony
	: ($header_o["X-URL"]="/ELCAriba/") && ($header_o["X-METHOD"]="POST")  //now you can eat chicken and don't have to steal
		
		//pass the headers to a specific strategy
		$result_t:=OWC_ELC_ProjectSymphony($header_o)
		
		$response:=OWC_sendResponse
		
	Else   //shame on you for probing, endpoint and method not defined
		//log and respond with 404 or fail silently
End case 
