extern Txt Kresponse;
extern Txt Kresponse__o;
extern Txt Kstorage;
extern Txt k0M9HM5Ao3to;
extern Txt kv3PgItHgVpk;
extern unsigned char D_proc_OWC__SENDRESPONSE[];
void proc_OWC__SENDRESPONSE( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__SENDRESPONSE);
	if (!ctx->doingAbort) try {
		Value_array_text lresponseHeaderValues__at;
		Value_array_text lresponseHeaderNames__at;
		new ( outResult) Txt();
		{
			Ref t0;
			t0.setLocalRef(ctx,lresponseHeaderNames__at.cv());
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t1;
			t1.setLocalRef(ctx,lresponseHeaderValues__at.cv());
			c.f.fLine=15;
			if (g->Call(ctx,(PCV[]){nullptr,t1.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Obj t2;
			c.f.fLine=18;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t3;
			if (g->GetMember(ctx,t2.cv(),Kstorage.cv(),t3.cv())) goto _0;
			Variant t4;
			if (g->GetMember(ctx,t3.cv(),Kresponse__o.cv(),t4.cv())) goto _0;
			Variant t5;
			if (g->GetMember(ctx,t4.cv(),kv3PgItHgVpk.cv(),t5.cv())) goto _0;
			Ref t6;
			t6.setLocalRef(ctx,lresponseHeaderNames__at.cv());
			Col t7;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),t5.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t7.cv(),t6.cv()},2,1562)) goto _0;
		}
		{
			Obj t8;
			c.f.fLine=19;
			if (g->Call(ctx,(PCV[]){t8.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t9;
			if (g->GetMember(ctx,t8.cv(),Kstorage.cv(),t9.cv())) goto _0;
			Variant t10;
			if (g->GetMember(ctx,t9.cv(),Kresponse__o.cv(),t10.cv())) goto _0;
			Variant t11;
			if (g->GetMember(ctx,t10.cv(),k0M9HM5Ao3to.cv(),t11.cv())) goto _0;
			Ref t12;
			t12.setLocalRef(ctx,lresponseHeaderValues__at.cv());
			Col t13;
			if (!g->GetValue(ctx,(PCV[]){t13.cv(),t11.cv(),nullptr})) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t13.cv(),t12.cv()},2,1562)) goto _0;
		}
		{
			Ref t14;
			t14.setLocalRef(ctx,lresponseHeaderValues__at.cv());
			Ref t15;
			t15.setLocalRef(ctx,lresponseHeaderNames__at.cv());
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){nullptr,t15.cv(),t14.cv()},2,660)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t16;
			c.f.fLine=25;
			if (g->Call(ctx,(PCV[]){t16.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t17;
			if (g->GetMember(ctx,t16.cv(),Kstorage.cv(),t17.cv())) goto _0;
			Variant t18;
			if (g->GetMember(ctx,t17.cv(),Kresponse__o.cv(),t18.cv())) goto _0;
			Variant t19;
			if (g->GetMember(ctx,t18.cv(),Kresponse.cv(),t19.cv())) goto _0;
			if (g->Call(ctx,(PCV[]){nullptr,t19.cv()},1,677)) goto _0;
		}
		{
			Obj t20;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t20.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t21;
			if (g->GetMember(ctx,t20.cv(),Kstorage.cv(),t21.cv())) goto _0;
			Variant t22;
			if (g->GetMember(ctx,t21.cv(),Kresponse__o.cv(),t22.cv())) goto _0;
			Variant t23;
			if (g->GetMember(ctx,t22.cv(),Kresponse.cv(),t23.cv())) goto _0;
			Txt t24;
			if (!g->GetValue(ctx,(PCV[]){t24.cv(),t23.cv(),nullptr})) goto _0;
			Res<Txt>(outResult)=t24.get();
		}
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
