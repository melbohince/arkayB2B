//%attributes = {}
/*
 Method: OWC_initHeaderObject   ( ) ->
 By: MelvinBohince @ 07/05/24, 14:00:53
 Description:
  Convert the header arrays into key-value object dictionary
    like:
      $header_o["Authorization"]:="Basic {encoded user:pwd}"
      $header_o["Content-Type"]:="text/xml"
      $header_o["Content-Length"]:="15344"
    
 Example Use:
  $header_o:=OWC_makeHeaderObject
  $expectedBodyLength_i:=Num($header_o["Content-Length"])
*/
// Modified by: MelvinBohince (7/6/24) remove Session.storage

#DECLARE()->$header_o : Object

var $i : Integer  //for interating over the header arrays
var $parsedURL_c : Collection

//get the headers
ARRAY TEXT:C222($httpHeaderNames_at; 0)
ARRAY TEXT:C222($httpHeaderValues_at; 0)

WEB GET HTTP HEADER:C697($httpHeaderNames_at; $httpHeaderValues_at)

//convert the header arrays to an object for ease of use and to pass by reference later
$header_o:=New shared object:C1526  //in case it gets put into Storage
Use ($header_o)
	//make a key-value pair for each header element
	For ($i; 1; Size of array:C274($httpHeaderNames_at))
		$header_o[$httpHeaderNames_at{$i}]:=$httpHeaderValues_at{$i}
	End for 
End use 

Use (Session:C1714.storage)  //to share with other processes
	Session:C1714.storage.header_o:=$header_o
End use 

//todo:use or remove this collection
$parsedURL_c:=Split string:C1554($header_o["X-URL"]; "/")  //just curious

return $header_o
