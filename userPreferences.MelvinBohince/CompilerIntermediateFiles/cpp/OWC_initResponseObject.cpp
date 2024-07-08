extern Txt KX_2DSTATUS;
extern Txt Kpush;
extern Txt Kresponse;
extern Txt Kresponse__o;
extern Txt Kstorage;
extern Txt k0M9HM5Ao3to;
extern Txt kv3PgItHgVpk;
extern unsigned char D_proc_OWC__INITRESPONSEOBJECT[];
void proc_OWC__INITRESPONSEOBJECT( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__INITRESPONSEOBJECT);
	if (!ctx->doingAbort) try {
		Obj l__4D__auto__mutex__0;
		Obj l__4D__auto__mutex__1;
		new ( outResult) Obj();
		{
			Obj t0;
			c.f.fLine=13;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1526)) goto _0;
			g->Check(ctx);
			Res<Obj>(outResult)=t0.get();
		}
		{
			Obj t1;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t1.cv(),Res<Obj>(outResult).cv()},1,1529)) goto _0;
			g->Check(ctx);
			l__4D__auto__mutex__0=t1.get();
		}
		c.f.fLine=15;
		if (g->SetMember(ctx,Res<Obj>(outResult).cv(),Kresponse.cv(),Parm<Txt>(inParams,inNbParam,1).cv())) goto _0;
		{
			Col t2;
			c.f.fLine=16;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1527)) goto _0;
			g->Check(ctx);
			if (g->SetMember(ctx,Res<Obj>(outResult).cv(),kv3PgItHgVpk.cv(),t2.cv())) goto _0;
		}
		{
			Variant t3;
			c.f.fLine=17;
			if (g->GetMember(ctx,Res<Obj>(outResult).cv(),kv3PgItHgVpk.cv(),t3.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),Kpush.cv(),KX_2DSTATUS.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Col t4;
			c.f.fLine=18;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1527)) goto _0;
			g->Check(ctx);
			if (g->SetMember(ctx,Res<Obj>(outResult).cv(),k0M9HM5Ao3to.cv(),t4.cv())) goto _0;
		}
		{
			Variant t5;
			c.f.fLine=19;
			if (g->GetMember(ctx,Res<Obj>(outResult).cv(),k0M9HM5Ao3to.cv(),t5.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),Kpush.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t6;
			l__4D__auto__mutex__0=t6.get();
		}
		{
			Obj t7;
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){t7.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t8;
			if (g->GetMember(ctx,t7.cv(),Kstorage.cv(),t8.cv())) goto _0;
			Obj t9;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv()},1,1529)) goto _0;
			l__4D__auto__mutex__1=t9.get();
		}
		{
			Obj t10;
			c.f.fLine=23;
			if (g->Call(ctx,(PCV[]){t10.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t11;
			if (g->GetMember(ctx,t10.cv(),Kstorage.cv(),t11.cv())) goto _0;
			if (g->SetMember(ctx,t11.cv(),Kresponse__o.cv(),Res<Obj>(outResult).cv())) goto _0;
		}
		{
			Obj t12;
			l__4D__auto__mutex__1=t12.get();
		}
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
