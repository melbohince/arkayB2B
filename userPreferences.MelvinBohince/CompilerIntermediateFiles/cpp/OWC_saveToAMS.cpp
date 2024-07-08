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
		Obj lstatus__o;
		Obj lams__e;
		Bool lTESTING;
		Long lNEEDS__MAPPED;
		new ( outResult) Bool();
		Res<Bool>(outResult)=Bool(0).get();
		{
			Long t0;
			t0=inNbExplicitParam;
			Bool t1;
			t1=2==t0.get();
			c.f.fLine=21;
			Obj t2;
			if (!(t1.get())) goto _2;
			{
				t2=Parm<Obj>(inParams,inNbParam,2).get();
				goto _3;
			}
_2:
			{
				Txt t4;
				Obj t5;
				proc_AMS__OPEN__REMOTEDATASTORE(glob,ctx,0,1,(PCV[]){t4.cv()},t5.cv());
				if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
				if (ctx->doingAbort) goto _0;
				t2=t5.get();
			}
_3:
			Parm<Obj>(inParams,inNbParam,2)=t2.get();
		}
		{
			Bool t6;
			t6=Parm<Obj>(inParams,inNbParam,2).isNull();
			if (!(t6.get())) goto _4;
		}
		goto _0;
_4:
		lTESTING=Bool(1).get();
		{
			Num t7;
			if (!(lTESTING.get())) goto _5;
			{
				t7=-222;
				goto _6;
			}
_5:
			{
				t7=0;
			}
_6:
			lNEEDS__MAPPED=(sLONG)lrint(t7.get());
		}
		{
			Variant t9;
			c.f.fLine=32;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,2).cv(),Kedi__Inbox.cv(),t9.cv())) goto _0;
			Variant t10;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv(),Knew.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t11;
			if (!g->GetValue(ctx,(PCV[]){t11.cv(),t10.cv(),nullptr})) goto _0;
			lams__e=t11.get();
		}
		{
			Bool t12;
			t12=lams__e.isNull();
			if (!(t12.get())) goto _7;
		}
		goto _0;
_7:
		{
			Obj t13;
			c.f.fLine=38;
			if (g->Call(ctx,(PCV[]){t13.cv()},0,1482)) goto _0;
			Variant t14;
			if (g->GetMember(ctx,t13.cv(),KWeb__Inbox.cv(),t14.cv())) goto _0;
			Variant t15;
			if (g->Call(ctx,(PCV[]){t15.cv(),t14.cv(),Kget.cv(),Parm<Variant>(inParams,inNbParam,1).cv()},3,1498)) goto _0;
			g->Check(ctx);
			Obj t16;
			if (!g->GetValue(ctx,(PCV[]){t16.cv(),t15.cv(),nullptr})) goto _0;
			llocal__e=t16.get();
		}
		{
			Variant t17;
			c.f.fLine=40;
			if (g->GetMember(ctx,llocal__e.cv(),KID.cv(),t17.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KID.cv(),t17.cv())) goto _0;
		}
		{
			Variant t18;
			c.f.fLine=43;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t18.cv())) goto _0;
			Date t19;
			if (g->Call(ctx,(PCV[]){t19.cv(),t18.cv()},1,102)) goto _0;
			Variant t20;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t20.cv())) goto _0;
			Time t21;
			if (g->Call(ctx,(PCV[]){t21.cv(),t20.cv()},1,179)) goto _0;
			Time t22;
			t22=t21.get();
			Date t23;
			t23=t19.get();
			Variant t24;
			proc_TSTIMESTAMP(glob,ctx,2,2,(PCV[]){t23.cv(),t22.cv()},t24.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KReceived.cv(),t24.cv())) goto _0;
		}
		{
			Variant t25;
			c.f.fLine=44;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t25.cv())) goto _0;
			Date t26;
			if (g->Call(ctx,(PCV[]){t26.cv(),t25.cv()},1,102)) goto _0;
			Date t27;
			t27=t26.get();
			if (g->SetMember(ctx,lams__e.cv(),KDate__Received.cv(),t27.cv())) goto _0;
		}
		{
			Variant t28;
			c.f.fLine=46;
			if (g->GetMember(ctx,llocal__e.cv(),KReceived__UTC.cv(),t28.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KPath.cv(),t28.cv())) goto _0;
		}
		{
			Variant t29;
			c.f.fLine=47;
			if (g->GetMember(ctx,llocal__e.cv(),KContent__Text.cv(),t29.cv())) goto _0;
			if (g->SetMember(ctx,lams__e.cv(),KContent__Text.cv(),t29.cv())) goto _0;
		}
		c.f.fLine=48;
		if (g->SetMember(ctx,lams__e.cv(),KMapped.cv(),lNEEDS__MAPPED.cv())) goto _0;
		{
			Variant t30;
			c.f.fLine=50;
			if (g->Call(ctx,(PCV[]){t30.cv(),lams__e.cv(),Ksave.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t31;
			if (!g->GetValue(ctx,(PCV[]){t31.cv(),t30.cv(),nullptr})) goto _0;
			lstatus__o=t31.get();
		}
		{
			Variant t32;
			c.f.fLine=51;
			if (g->GetMember(ctx,lstatus__o.cv(),Ksuccess.cv(),t32.cv())) goto _0;
			Bool t33;
			if (!g->GetValue(ctx,(PCV[]){t33.cv(),t32.cv(),nullptr})) goto _0;
			if (!(t33.get())) goto _8;
		}
		{
			Txt t34;
			c.f.fLine=53;
			if (g->Call(ctx,(PCV[]){t34.cv()},0,1445)) goto _0;
			if (g->SetMember(ctx,llocal__e.cv(),KSentToAMS__UTC.cv(),t34.cv())) goto _0;
		}
		{
			Variant t35;
			c.f.fLine=54;
			if (g->Call(ctx,(PCV[]){t35.cv(),llocal__e.cv(),Ksave.cv()},2,1498)) goto _0;
			g->Check(ctx);
			Obj t36;
			if (!g->GetValue(ctx,(PCV[]){t36.cv(),t35.cv(),nullptr})) goto _0;
			lstatus__o=t36.get();
		}
_8:
		{
			Variant t37;
			c.f.fLine=57;
			if (g->GetMember(ctx,lstatus__o.cv(),Ksuccess.cv(),t37.cv())) goto _0;
			Bool t38;
			if (!g->GetValue(ctx,(PCV[]){t38.cv(),t37.cv(),nullptr})) goto _0;
			Res<Bool>(outResult)=t38.get();
		}
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
