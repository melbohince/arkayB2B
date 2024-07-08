extern Txt KContent__Text;
extern Txt KID;
extern Txt KPath;
extern Txt KPayloadID;
extern Txt KReceived__UTC;
extern Txt KSentToAMS__UTC;
extern Txt KWeb__Inbox;
extern Txt Knew;
extern Txt Knope;
extern Txt Ksave;
extern Txt Ksuccess;
extern unsigned char D_proc_OWC__SAVETOINBOX[];
void proc_OWC__SAVETOINBOX( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__SAVETOINBOX);
	if (!ctx->doingAbort) try {
		Obj linbox__e;
		Bool lremoteSuccess;
		Obj lstatus__o;
		Long lNO__CURRENT__RECORD;
		new ( outResult) Long();
		lNO__CURRENT__RECORD=-1;
		Res<Long>(outResult)=lNO__CURRENT__RECORD.get();
		{
			Obj t0;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1482)) goto _0;
			Variant t1;
			if (g->GetMember(ctx,t0.cv(),KWeb__Inbox.cv(),t1.cv())) goto _0;
			Variant t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv(),Knew.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t3;
			if (!g->GetValue(ctx,(PCV[]){t3.cv(),t2.cv(),nullptr})) goto _0;
			linbox__e=t3.get();
		}
		{
			Txt t4;
			c.f.fLine=23;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1445)) goto _0;
			if (g->SetMember(ctx,linbox__e.cv(),KReceived__UTC.cv(),t4.cv())) goto _0;
		}
		c.f.fLine=24;
		if (g->SetMember(ctx,linbox__e.cv(),KPath.cv(),Parm<Txt>(inParams,inNbParam,1).cv())) goto _0;
		{
			Variant t5;
			c.f.fLine=25;
			if (!g->GetValue(ctx,(PCV[]){t5.cv(),Parm<Ptr>(inParams,inNbParam,3).cv(),(PCV)-1,nullptr})) goto _0;
			if (g->SetMember(ctx,linbox__e.cv(),KContent__Text.cv(),t5.cv())) goto _0;
		}
		c.f.fLine=26;
		if (g->SetMember(ctx,linbox__e.cv(),KSentToAMS__UTC.cv(),Knope.cv())) goto _0;
		c.f.fLine=27;
		if (g->SetMember(ctx,linbox__e.cv(),KPayloadID.cv(),Parm<Txt>(inParams,inNbParam,2).cv())) goto _0;
		{
			Variant t6;
			c.f.fLine=28;
			if (g->Call(ctx,(PCV[]){t6.cv(),linbox__e.cv(),Ksave.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t7;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),t6.cv(),nullptr})) goto _0;
			lstatus__o=t7.get();
		}
		{
			Variant t8;
			c.f.fLine=30;
			if (g->GetMember(ctx,lstatus__o.cv(),Ksuccess.cv(),t8.cv())) goto _0;
			Bool t9;
			if (!g->GetValue(ctx,(PCV[]){t9.cv(),t8.cv(),nullptr})) goto _0;
			if (!(t9.get())) goto _2;
		}
		{
			Variant t10;
			c.f.fLine=31;
			if (g->GetMember(ctx,linbox__e.cv(),KID.cv(),t10.cv())) goto _0;
			Long t11;
			if (!g->GetValue(ctx,(PCV[]){t11.cv(),t10.cv(),nullptr})) goto _0;
			Res<Long>(outResult)=t11.get();
		}
_2:
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
