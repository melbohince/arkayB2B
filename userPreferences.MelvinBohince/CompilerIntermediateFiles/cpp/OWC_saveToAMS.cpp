extern Txt KContent__Text;
extern Txt KDate__Received;
extern Txt KID;
extern Txt KMapped;
extern Txt KPath;
extern Txt KReceived;
extern Txt KReceived__UTC;
extern Txt KSentToAMS__UTC;
extern Txt KWeb__Inbox;
extern Txt Kedi__Inbox;
extern Txt Kget;
extern Txt Knew;
extern Txt Ksave;
extern Txt Ksuccess;
Asm4d_Proc proc_AMS__OPEN__REMOTEDATASTORE;
Asm4d_Proc proc_TSTIMESTAMP;
extern unsigned char D_proc_OWC__SAVETOAMS[];
void proc_OWC__SAVETOAMS( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__SAVETOAMS);
	if (!ctx->doingAbort) try {
		Obj llocal__e;
		Obj lams__ds;
		Obj lstatus__o;
		Variant lams__e;
		Bool lTESTING;
		Long lNEEDS__MAPPED;
		new ( outResult) Bool();
		Res<Bool>(outResult)=Bool(0).get();
		lTESTING=Bool(1).get();
		{
			Num t0;
			if (!(lTESTING.get())) goto _2;
			{
				t0=-222;
				goto _3;
			}
_2:
			{
				t0=0;
			}
_3:
			lNEEDS__MAPPED=(sLONG)lrint(t0.get());
		}
		{
			Txt t2;
			Obj t3;
			c.f.fLine=24;
			proc_AMS__OPEN__REMOTEDATASTORE(glob,ctx,0,1,(PCV[]){t2.cv()},t3.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lams__ds=t3.get();
		}
		{
			Bool t4;
			t4=lams__ds.isNull();
			if (!(t4.get())) goto _4;
		}
		goto _0;
_4:
		{
			Variant t5;
			c.f.fLine=29;
			if (g->GetMember(ctx,lams__ds.cv(),Kedi__Inbox.cv(),t5.cv())) goto _0;
			Variant t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv(),Knew.cv()},2,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t6.cv(),lams__e.cv(),nullptr})) goto _0;
		}
		{
			Variant t7;
			c.f.fLine=30;
			if (!g->GetValue(ctx,(PCV[]){t7.cv(),lams__e.cv(),nullptr})) goto _0;
			Bool t8;
			if (g->OperationOnAny(ctx,6,t7.cv(),Value_null().cv(),t8.cv())) goto _0;
			if (!(t8.get())) goto _5;
		}
		goto _0;
_5:
		{
			Variant t9;
			c.f.fLine=35;
			if (g->GetMember(ctx,lams__ds.cv(),Kedi__Inbox.cv(),t9.cv())) goto _0;
			Variant t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv(),Knew.cv()},2,1498)) goto _0;
			g->Check(ctx);
			if (!g->SetValue(ctx,(PCV[]){t10.cv(),lams__e.cv(),nullptr})) goto _0;
		}
		{
			Obj t11;
			c.f.fLine=37;
			if (g->Call(ctx,(PCV[]){t11.cv()},0,1482)) goto _0;
			Variant t12;
			if (g->GetMember(ctx,t11.cv(),KWeb__Inbox.cv(),t12.cv())) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),Kget.cv(),Parm<Variant>(inParams,inNbParam,1).cv()},3,1498)) goto _0;
			g->Check(ctx);
			Obj t14;
			if (!g->GetValue(ctx,(PCV[]){t14.cv(),t13.cv(),nullptr})) goto _0;
			llocal__e=t14.get();
		}
		{
			Variant t15;
			c.f.fLine=39;
			if (g->GetMember(ctx,llocal__e.cv(),KID.cv(),t15.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KID.cv(),t15.cv())) goto _0;
		}
		{
			Variant t16;
			c.f.fLine=42;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t16.cv())) goto _0;
			Date t17;
			if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv()},1,102)) goto _0;
			Variant t18;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t18.cv())) goto _0;
			Time t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),t18.cv()},1,179)) goto _0;
			Time t20;
			t20=t19.get();
			Date t21;
			t21=t17.get();
			Variant t22;
			proc_TSTIMESTAMP(glob,ctx,2,2,(PCV[]){t21.cv(),t20.cv()},t22.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KReceived.cv(),t22.cv())) goto _0;
		}
		{
			Variant t23;
			c.f.fLine=43;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t23.cv())) goto _0;
			Date t24;
			if (g->Call(ctx,(PCV[]){t24.cv(),t23.cv()},1,102)) goto _0;
			Date t25;
			t25=t24.get();
			if (g->SetMember(ctx,lams__e.cv(),KDate__Received.cv(),t25.cv())) goto _0;
		}
		{
			Variant t26;
			c.f.fLine=45;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t26.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KPath.cv(),t26.cv())) goto _0;
		}
		{
			Variant t27;
			c.f.fLine=46;
			if (g->GetMember(ctx,llocal__e.cv(),KContent__Text.cv(),t27.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KContent__Text.cv(),t27.cv())) goto _0;
		}
		c.f.fLine=47;
		if (g->SetMember(ctx,lams__e.cv(),KMapped.cv(),lNEEDS__MAPPED.cv())) goto _0;
		{
			Variant t28;
			c.f.fLine=49;
			if (g->Call(ctx,(PCV[]){t28.cv(),lams__e.cv(),Ksave.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t29;
			if (!g->GetValue(ctx,(PCV[]){t29.cv(),t28.cv(),nullptr})) goto _0;
			lstatus__o=t29.get();
		}
		{
			Variant t30;
			c.f.fLine=50;
			if (g->GetMember(ctx,lstatus__o.cv(),Ksuccess.cv(),t30.cv())) goto _0;
			Bool t31;
			if (!g->GetValue(ctx,(PCV[]){t31.cv(),t30.cv(),nullptr})) goto _0;
			if (!(t31.get())) goto _6;
		}
		{
			Txt t32;
			c.f.fLine=52;
			if (g->Call(ctx,(PCV[]){t32.cv()},0,1445)) goto _0;
			if (g->SetMember(ctx,llocal__e.cv(),KSentToAMS__UTC.cv(),t32.cv())) goto _0;
		}
		{
			Variant t33;
			c.f.fLine=53;
			if (g->Call(ctx,(PCV[]){t33.cv(),llocal__e.cv(),Ksave.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t34;
			if (!g->GetValue(ctx,(PCV[]){t34.cv(),t33.cv(),nullptr})) goto _0;
			lstatus__o=t34.get();
		}
_6:
		{
			Variant t35;
			c.f.fLine=56;
			if (g->GetMember(ctx,lstatus__o.cv(),Ksuccess.cv(),t35.cv())) goto _0;
			Bool t36;
			if (!g->GetValue(ctx,(PCV[]){t36.cv(),t35.cv(),nullptr})) goto _0;
			Res<Bool>(outResult)=t36.get();
		}
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
