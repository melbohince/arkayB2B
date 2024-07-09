//%attributes = {}
/*
 Method: Inbox_RecentMessages   ( n) ->
 By: MelvinBohince @ 07/09/24, 07:17:46
 Description:
  Return a json object of the (n) most recent messages saved

 Example Use:
   $recentMessages_json:=Inbox_RecentMessages(3)
*/
/*
returns:
{
    "recent_messages": [
        {
            "ID": 30,
            "Received_UTC": "2024-07-07T00:28:58.842Z",
            "PayloadID": "005056B3EC831EEDB1E7EFC1BAD0116D"
        },
        {
            "ID": 29,
            "Received_UTC": "2024-07-06T02:10:01.722Z",
            "PayloadID": null
        },
        {
            "ID": 28,
            "Received_UTC": "2024-07-06T02:07:31.887Z",
            "PayloadID": null
        }
    ]
}
*/

#DECLARE($collectionLimitor : Integer)->$recentMessages_json : Text

var $inbox_c : Collection  //cs.Web_InboxSelection
var $recentMessages_o : Object

//default to last 5
$collectionLimitor:=(Count parameters:C259=1) ? $collectionLimitor : 5

//find the messages
$inbox_c:=ds:C1482.Web_Inbox.all()\
.orderBy("ID desc")\
.slice(0; $collectionLimitor)\
.toCollection("ID,Received_UTC,PayloadID")

$recentMessages_o:=New object:C1471("recent_messages"; $inbox_c)

$recentMessages_json:=JSON Stringify:C1217($recentMessages_o; *)

//ALERT($recentMessages_json)
