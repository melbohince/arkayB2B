//%attributes = {}
/*
 Method: OWC_setResponse   ( ) ->
 By: MelvinBohince @ 07/05/24, 14:34:57
 Description:
  

 Example Use:
  
*/

#DECLARE($response : Text; $responseHeaderValue : Text)->$responseToSend : Text

Use (Session:C1714.storage)
	Use (Session:C1714.storage.response_o)
		
		Session:C1714.storage.response_o.response:=$response
		Session:C1714.storage.response_o.responseHeaderValues_c[0]:=$responseHeaderValue
		
	End use 
End use 

$responseToSend:=Session:C1714.storage.response_o.response

return $responseToSend
