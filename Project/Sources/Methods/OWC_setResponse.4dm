//%attributes = {}
/*
 Method: OWC_setResponse   ( ) ->
 By: MelvinBohince @ 07/05/24, 14:34:57
 Description:
  Set the response and its header value in the
    Session.storage object

 Example Use:
  $result_t:=OWC_setResponse("402 Bad Request")//to swap out the defaulted response
    then:
  $result_t:=OWC_sendResponse
*/

#DECLARE($response : Text)->$responseToSend : Text

Use (Session:C1714.storage)
	Use (Session:C1714.storage.response_o)
		
		Session:C1714.storage.response_o.response:=$response
		Session:C1714.storage.response_o.responseHeaderValues_c[0]:=$response
		
	End use 
End use 

$responseToSend:=Session:C1714.storage.response_o.response

return $responseToSend
