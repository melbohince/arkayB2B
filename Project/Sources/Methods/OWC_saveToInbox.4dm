//%attributes = {}
/*
 Method: OWC_saveToInbox   ( ) ->
 By: MelvinBohince @ 07/05/24, 21:03:20
 Description:
  Save http web body locally

 Example Use:
  $success:=OWC_saveToInbox($pathValue;->$body)
*/

#DECLARE($pathValue : Text; $body_ptr : Pointer)->$inbox_pkid : Integer

var $inbox_e : cs:C1710.Web_InboxEntity
var $status_o : Object
var $remoteSuccess : Boolean

$inbox_pkid:=0

$inbox_e:=ds:C1482.Web_Inbox.new()
$inbox_e.Received_UTC:=Timestamp:C1445
$inbox_e.Path:=$pathValue
$inbox_e.Content_Text:=$body_ptr->
$inbox_e.SentToAMS_UTC:="nope"  //will be a nope, Timestamp, or error
$status_o:=$inbox_e.save()

If ($status_o.success)
	$inbox_pkid:=$inbox_e.ID
End if 

return $inbox_pkid
