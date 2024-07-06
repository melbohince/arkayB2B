//%attributes = {}
var $tradingPartner_e : cs:C1710.Trading_PartnersEntity

$tradingPartner_e:=ds:C1482.Trading_Partners.new()
$tradingPartner_e.RegisteredIP:="1.1.1.1"
$tradingPartner_e.EndPoint:="ELCAriba"
$tradingPartner_e.save()

ABORT:C156