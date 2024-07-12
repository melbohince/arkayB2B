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

var $body; $xmlRef_t; $payloadID_t : Text
var $expectedBodyLength_i; $actualBodyLength : Integer
var $requestBody_blob : Blob
var $remoteSuccess : Boolean
var $inbox_pkid : Integer
var $XML_PARSE_FAILURE : Integer:=0
var $EXPECTED_CONTENT_TYPE : Text:="text/xml; charset=UTF-8"  //being picky

$result_t:="202 Accepted"  // see https://developer.mozilla.org/en-US/docs/Web/HTTP/Status


//mark:-Test Content-Type
If ($header_o["Content-Type"]#$EXPECTED_CONTENT_TYPE)
	$result_t:=OWC_setResponse("415 Unsupported Media Type")
	return $result_t
End if 

//mark:-Test Content-Length
$expectedBodyLength_i:=Num:C11($header_o["Content-Length"])

//get body as blob so size in bytes can be checked
WEB GET HTTP BODY:C814($requestBody_blob)
$actualBodyLength:=BLOB size:C605($requestBody_blob)

If ($actualBodyLength#$expectedBodyLength_i)
	$result_t:=OWC_setResponse("411 Length Required")
	return $result_t
End if 

//mark:-Test Parse XML
//convert body blob to text
$body:=BLOB to text:C555($requestBody_blob; UTF8 text without length:K22:17)

//ON ERR CALL("e_XML_Problem")
$xmlRef_t:=DOM Parse XML variable:C720($body)
If (ok=$XML_PARSE_FAILURE)  //& (error#0) 
	$result_t:=OWC_setResponse("422 Unprocessable Content")
	return $result_t
End if 

DOM GET XML ATTRIBUTE BY NAME:C728($xmlRef_t; "payloadID"; $payloadID_t)

//mark:-If passed tests, save body to the Web_Inbox and AMS.edi_Inbox

//save body locally
$pathValue:=$header_o["X-METHOD"]+" "+$header_o["X-URL"]
$inbox_pkid:=Inbox_SaveMessage($pathValue; $payloadID_t; ->$body)

If ($inbox_pkid>0)
	$remoteSuccess:=AMS_SaveInboxMsg($inbox_pkid)
	
	If (Not:C34($remoteSuccess))  //no worries, will get it later
		//todo:set up a worker
		Inbox_SyncToAMS
	End if 
	
Else 
	$result_t:=OWC_setResponse("500 Internal Server Error")
End if 

return $result_t  //default is "202 Accepted", or last error of 500
