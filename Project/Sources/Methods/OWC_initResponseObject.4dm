//%attributes = {}
/*
 Method: OWC_initResponseObject   ( ) ->
 By: MelvinBohince @ 07/05/24, 14:17:48
 Description:
  Prepare an object for the response

 Example Use:
  $response_o:=OWC_makeResponseObject
*/

#DECLARE($defaultResponse : Text)->$response_o : Object

$response_o:=New shared object:C1526
Use ($response_o)
	$response_o.response:=$defaultResponse  //default to non-specific problem
	$response_o.responseHeaderNames_c:=New shared collection:C1527
	$response_o.responseHeaderNames_c.push("X-STATUS")  //same in all cases
	$response_o.responseHeaderValues_c:=New shared collection:C1527  //can be good or bad
	$response_o.responseHeaderValues_c.push($defaultResponse)
End use 

Use (Session:C1714.storage)  //to share with other processes
	Session:C1714.storage.response_o:=$response_o
End use 

return $response_o
