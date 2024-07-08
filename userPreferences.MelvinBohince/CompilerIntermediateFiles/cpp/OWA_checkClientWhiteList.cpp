extern Txt K10_2E0_2E0_2E162;
extern Txt K127_2E0_2E0_2E1;
extern Txt K130_2E214_2E184_2E67;
extern Txt K192_2E168_2E1_2E51;
extern Txt K1_2E1_2E1_2E1;
extern Txt KELCAriba;
extern Txt Kfirst;
extern Txt KindexOf;
extern Txt Kpush;
extern Txt Kquery;
extern Txt kG4sn21lRB5I;
extern Txt kingcQL_wqus;
extern unsigned char D_proc_OWA__CHECKCLIENTWHITELIST[];
void proc_OWA__CHECKCLIENTWHITELIST( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWA__CHECKCLIENTWHITELIST);
	if (!ctx->doingAbort) try {
		Long lNOT__FOUND;
		Col lallowedClientIPs__c;
		Obj ltradingPartner__e;
		new ( outResult) Bool();
		{
			Long t0;
			t0=inNbExplicitParam;
			if (0!=t0.get()) goto _2;
		}
		Parm<Txt>(inParams,inNbParam,1)=K1_2E1_2E1_2E1.get();
		Parm<Txt>(inParams,inNbParam,2)=KELCAriba.get();
_2:
		Res<Bool>(outResult)=Bool(1).get();
		{
			Obj t2;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1482)) goto _0;
			Variant t3;
			if (g->GetMember(ctx,t2.cv(),kingcQL_wqus.cv(),t3.cv())) goto _0;
			Variant t4;
			if (g->Call(ctx,(PCV[]){t4.cv(),t3.cv(),Kquery.cv(),kG4sn21lRB5I.cv(),Parm<Txt>(inParams,inNbParam,1).cv(),Parm<Txt>(inParams,inNbParam,2).cv()},5,1498)) goto _0;
			g->Check(ctx);
			Variant t5;
			if (g->Call(ctx,(PCV[]){t5.cv(),t4.cv(),Kfirst.cv()},2,1498)) goto _0;
			Obj t6;
			if (!g->GetValue(ctx,(PCV[]){t6.cv(),t5.cv(),nullptr})) goto _0;
			ltradingPartner__e=t6.get();
		}
		{
			Bool t7;
			t7=!ltradingPartner__e.isNull();
			if (!(t7.get())) goto _3;
		}
		goto _0;
		goto _4;
_3:
		{
			Col t8;
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1472)) goto _0;
			g->Check(ctx);
			lallowedClientIPs__c=t8.get();
		}
		lNOT__FOUND=-1;
		{
			Bool t9;
			t9=g->CompareString(ctx,Parm<Txt>(inParams,inNbParam,2).get(),KELCAriba.get())==0;
			if (!(t9.get())) goto _6;
		}
		c.f.fLine=37;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K127_2E0_2E0_2E1.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=38;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K10_2E0_2E0_2E162.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=39;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K192_2E168_2E1_2E51.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=40;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K130_2E214_2E184_2E67.cv()},3,1500)) goto _0;
		g->Check(ctx);
		goto _5;
_6:
_5:
		{
			Variant t10;
			c.f.fLine=46;
			if (g->Call(ctx,(PCV[]){t10.cv(),lallowedClientIPs__c.cv(),KindexOf.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},3,1498)) goto _0;
			g->Check(ctx);
			Bool t11;
			if (g->OperationOnAny(ctx,6,t10.cv(),lNOT__FOUND.cv(),t11.cv())) goto _0;
			if (!(t11.get())) goto _7;
		}
		Res<Bool>(outResult)=Bool(0).get();
		goto _8;
_7:
		Res<Bool>(outResult)=Bool(1).get();
_8:
		goto _0;
_4:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
