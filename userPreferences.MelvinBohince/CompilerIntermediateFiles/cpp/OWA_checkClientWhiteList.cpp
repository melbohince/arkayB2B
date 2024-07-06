extern Txt K10_2E0_2E0_2E162;
extern Txt K127_2E0_2E0_2E1;
extern Txt K130_2E214_2E184_2E67;
extern Txt K192_2E168_2E1_2E51;
extern Txt KELCAriba;
extern Txt KindexOf;
extern Txt Kpush;
extern unsigned char D_proc_OWA__CHECKCLIENTWHITELIST[];
void proc_OWA__CHECKCLIENTWHITELIST( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWA__CHECKCLIENTWHITELIST);
	if (!ctx->doingAbort) try {
		Long lNOT__FOUND;
		Col lallowedClientIPs__c;
		new ( outResult) Bool();
		{
			Col t0;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1472)) goto _0;
			g->Check(ctx);
			lallowedClientIPs__c=t0.get();
		}
		lNOT__FOUND=-1;
		{
			Bool t1;
			t1=g->CompareString(ctx,Parm<Txt>(inParams,inNbParam,2).get(),KELCAriba.get())==0;
			if (!(t1.get())) goto _3;
		}
		c.f.fLine=24;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K127_2E0_2E0_2E1.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=25;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K10_2E0_2E0_2E162.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=26;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K192_2E168_2E1_2E51.cv()},3,1500)) goto _0;
		g->Check(ctx);
		c.f.fLine=27;
		if (g->Call(ctx,(PCV[]){nullptr,lallowedClientIPs__c.cv(),Kpush.cv(),K130_2E214_2E184_2E67.cv()},3,1500)) goto _0;
		g->Check(ctx);
		goto _2;
_3:
_2:
		{
			Variant t2;
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){t2.cv(),lallowedClientIPs__c.cv(),KindexOf.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},3,1498)) goto _0;
			g->Check(ctx);
			Bool t3;
			if (g->OperationOnAny(ctx,6,t2.cv(),lNOT__FOUND.cv(),t3.cv())) goto _0;
			if (!(t3.get())) goto _4;
		}
		Res<Bool>(outResult)=Bool(0).get();
		goto _5;
_4:
		Res<Bool>(outResult)=Bool(1).get();
_5:
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
