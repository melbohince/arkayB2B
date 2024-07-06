//%attributes = {}
/*
 Method: OWC_sendResponse   ( ) ->
 By: MelvinBohince @ 07/05/24, 14:22:48
 Description:
  

 Example Use:
  
*/

#DECLARE()->$responseSent : Text

//get ready for a response
ARRAY TEXT:C222($responseHeaderNames_at; 0)
ARRAY TEXT:C222($responseHeaderValues_at; 0)

//extract the response header and value
COLLECTION TO ARRAY:C1562(Session:C1714.storage.response_o.responseHeaderNames_c; $responseHeaderNames_at)
COLLECTION TO ARRAY:C1562(Session:C1714.storage.response_o.responseHeaderValues_c; $responseHeaderValues_at)

//prep the response
WEB SET HTTP HEADER:C660($responseHeaderNames_at; $responseHeaderValues_at)

//send it
WEB SEND TEXT:C677(Session:C1714.storage.response_o.response)

return Session:C1714.storage.response_o.response
