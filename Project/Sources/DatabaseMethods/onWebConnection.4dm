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

var $result_t : Text

//mark:-Decide what route a client is looking for

Case of 
		
		//mark:-.    ELC Project Symphony
	: (Session:C1714.storage.header_o["X-URL"]="/ELCAriba/") && (Session:C1714.storage.header_o["X-METHOD"]="POST")  //now you can eat chicken and don't have to steal
		
		//pass the headers to a specific strategy
		$result_t:=OWC_ELC_ProjectSymphony(Session:C1714.storage.header_o)
		
		$result_t:=OWC_sendResponse
		
	: (Session:C1714.storage.header_o["X-URL"]="/ELCAriba/") && (Session:C1714.storage.header_o["X-METHOD"]="GET")  //for the OCD
		
		$recentMessages_json:=Inbox_RecentMessages(3)
		
		
		
		//$result_t:=OWC_sendResponse
		
		
	Else   //shame on you for probing, endpoint and method not defined
		//log and respond with 404 or fail silently
		$result_t:=OWC_setResponse("405 Method Not Allowed")
		$result_t:=OWC_sendResponse
End case 
