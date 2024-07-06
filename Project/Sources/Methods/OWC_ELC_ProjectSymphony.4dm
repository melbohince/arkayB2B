//%attributes = {}
/*
 Method: OWC_ELC_ProjectSymphony   ( ) ->
 By: MelvinBohince @ 07/03/24, 23:29:30
 Description:
  verify the integrity of the ELC web request and
    if valid, save the body to the edi_inbox

  the return object will allow the caller to set up
    a http header and send the response
*/

#DECLARE($header_o : Object)->$result_t : Text

var $body; $EXPECTED_CONTENT_TYPE; $xmlRef_t : Text
var $expectedBodyLength_i; $actualBodyLength; $XML_PARSE_FAILURE : Integer
var $requestBody_blob : Blob

$result_t:="200 OK"
$EXPECTED_CONTENT_TYPE:="text/xml; charset=UTF-8"  //being picky
$XML_PARSE_FAILURE:=0

If ($header_o["Content-Type"]#$EXPECTED_CONTENT_TYPE)
	//mark:-.        fail--unexpected body format
	$result_t:=OWC_setResponse("441"; "401 Bad Request")
	return 
End if 

$expectedBodyLength_i:=Num:C11($header_o["Content-Length"])

//get body as blob so size in bytes can be checked
WEB GET HTTP BODY:C814($requestBody_blob)
$actualBodyLength:=BLOB size:C605($requestBody_blob)

If ($actualBodyLength#$expectedBodyLength_i)
	//mark:-.        fail--incomplete message, no point in continuing
	$result_t:=OWC_setResponse("442"; "402 Bad Request")
	return 
End if 

//convert body blob to text
$body:=BLOB to text:C555($requestBody_blob; UTF8 text without length:K22:17)

//ON ERR CALL("e_XML_Problem")
$xmlRef_t:=DOM Parse XML variable:C720($body)
If (ok=0)  //& (error#0) 
	//mark:-.        fail--XML doesn't parse, no point in continuing
	$result_t:=OWC_setResponse("443"; "403 Bad Request")
	return 
End if 

//mark:-.        save body to the edi_inbox

//save body locally
$pathValue:=$header_o["X-METHOD"]+" "+$header_o["X-URL"]
$inbox_pkid:=OWC_saveToInbox($pathValue; ->$body)

If ($inbox_pkid>0)
	$remoteSuccess:=OWC_saveToAMS($inbox_pkid)
	
	If (Not:C34($remoteSuccess))  //no worries, will get it later
		//if remote save is not successful, will need a second pass in a batch
		// like: 
		//.   $inbox_es:=ds.Web_Inbox.query("SentToAMS_UTC = :1"; "nope")
		//.   If ($inbox_es.length=0)
		//.     return $success
		//.   end if
		//.   For each ($inbox_e; $inbox_es)...try to save to AMS
	End if 
	
Else 
	$result_t:=OWC_setResponse("550"; "550 Internal Error")
End if 

