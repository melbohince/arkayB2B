//%attributes = {}
/*
 Method: Inbox_SyncToAMS   ( ) ->
 By: MelvinBohince @ 07/06/24, 10:21:35
 Description:
  second try for messages saved locally but
    failed to send to AMS

 Example Use:
  
*/

#DECLARE()->$success : Boolean

var $inbox_e : cs:C1710.Web_InboxEntity
var $inbox_es : cs:C1710.Web_InboxSelection
var $NOT_SENT_TO_AMS : Text:="nope"  //will be a nope, Timestamp, or error
var $ams_ds : cs:C1710.DataStore
var $remoteSuccess : Boolean

$success:=True:C214

//todo:implement as a 4D.worker
//if remote save is not successful, will need a second pass in a batch

$inbox_es:=ds:C1482.Web_Inbox.query("SentToAMS_UTC = :1"; $NOT_SENT_TO_AMS)
If ($inbox_es.length=0)
	return $success
End if 

$ams_ds:=aMs_Open_RemoteDataStore
If ($ams_ds=Null:C1517)
	$success:=False:C215
	return $success
End if 

For each ($inbox_e; $inbox_es)  //...tryto save to AMS
	$remoteSuccess:=AMS_SaveInboxMsg($inbox_e.ID; $ams_ds)
	//if it fails we'll get it in another session
End for each 
