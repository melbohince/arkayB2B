extern Txt Kresponse;
extern Txt Kresponse__o;
extern Txt Kstorage;
extern Txt k0M9HM5Ao3to;
extern unsigned char D_proc_OWC__SETRESPONSE[];
void proc_OWC__SETRESPONSE( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__SETRESPONSE);
	if (!ctx->doingAbort) try {
		Obj l__4D__auto__mutex__0;
		Obj l__4D__auto__mutex__1;
		new ( outResult) Txt();
		{
			Obj t0;
			c.f.fLine=13;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t1;
			if (g->GetMember(ctx,t0.cv(),Kstorage.cv(),t1.cv())) goto _0;
			Obj t2;
			if (g->Call(ctx,(PCV[]){t2.cv(),t1.cv()},1,1529)) goto _0;
			l__4D__auto__mutex__1=t2.get();
		}
		{
			Obj t3;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t4;
			if (g->GetMember(ctx,t3.cv(),Kstorage.cv(),t4.cv())) goto _0;
			Variant t5;
			if (g->GetMember(ctx,t4.cv(),Kresponse__o.cv(),t5.cv())) goto _0;
			Obj t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv()},1,1529)) goto _0;
			l__4D__auto__mutex__0=t6.get();
		}
		{
			Obj t7;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t8;
			if (g->GetMember(ctx,t7.cv(),Kstorage.cv(),t8.cv())) goto _0;
			Variant t9;
			if (g->GetMember(ctx,t8.cv(),Kresponse__o.cv(),t9.cv())) goto _0;
			if (g->SetMember(ctx,t9.cv(),Kresponse.cv(),Parm<Txt>(inParams,inNbParam,1).cv())) goto _0;
		}
		{
			Obj t10;
			c.f.fLine=17;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t11;
			if (g->GetMember(ctx,t10.cv(),Kstorage.cv(),t11.cv())) goto _0;
			Variant t12;
			if (g->GetMember(ctx,t11.cv(),Kresponse__o.cv(),t12.cv())) goto _0;
			Variant t13;
			if (g->GetMember(ctx,t12.cv(),k0M9HM5Ao3to.cv(),t13.cv())) goto _0;
			if (g->SetMember(ctx,t13.cv(),Long(0).cv(),Parm<Txt>(inParams,inNbParam,2).cv())) goto _0;
		}
		{
			Obj t14;
			l__4D__auto__mutex__0=t14.get();
		}
		{
			Obj t15;
			l__4D__auto__mutex__1=t15.get();
		}
		{
			Obj t16;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t16.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t17;
			if (g->GetMember(ctx,t16.cv(),Kstorage.cv(),t17.cv())) goto _0;
			Variant t18;
			if (g->GetMember(ctx,t17.cv(),Kresponse__o.cv(),t18.cv())) goto _0;
			Variant t19;
			if (g->GetMember(ctx,t18.cv(),Kresponse.cv(),t19.cv())) goto _0;
			Txt t20;
			if (!g->GetValue(ctx,(PCV[]){t20.cv(),t19.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t20.get();
		}
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
