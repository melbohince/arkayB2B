extern Txt KAuthorization;
extern Txt KBasic_20;
extern Txt KELCAriba;
extern Txt KWeb__Users;
extern Txt Kdemo_3Ademo;
extern Txt Kfirst;
extern Txt KindexOf;
extern Txt Kpush;
extern Txt Kquery;
extern Txt kDMtTBwwOQgY;
extern Txt kmyjgtiEnStc;
extern unsigned char D_proc_OWA__CHECKUSERCREDENTIALS[];
void proc_OWA__CHECKUSERCREDENTIALS( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWA__CHECKUSERCREDENTIALS);
	if (!ctx->doingAbort) try {
		Obj lwebUser__e;
		Long lNOT__FOUND;
		Txt lauthorizationValue;
		Value_array_text lhttpHeaderValues__at;
		Txt lencodedUser;
		Col lallowedAuthentications__c;
		Value_array_text lhttpHeaderNames__at;
		new ( outResult) Bool();
		{
			Long t0;
			t0=inNbExplicitParam;
			if (0!=t0.get()) goto _2;
		}
		Parm<Txt>(inParams,inNbParam,1)=KELCAriba.get();
		{
			Ref t2;
			t2.setLocalRef(ctx,lencodedUser.cv());
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){nullptr,kDMtTBwwOQgY.cv(),t2.cv()},2,895)) goto _0;
			g->Check(ctx);
		}
		g->AddString(KBasic_20.get(),lencodedUser.get(),lauthorizationValue.get());
		goto _3;
_2:
		{
			Ref t4;
			t4.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){nullptr,t4.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t5;
			t5.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t6;
			t6.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			Ref t7;
			t7.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=35;
			if (g->Call(ctx,(PCV[]){nullptr,t7.cv(),t6.cv()},2,697)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t8;
			t8.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			Long t9;
			c.f.fLine=36;
			if (g->Call(ctx,(PCV[]){t9.cv(),t8.cv(),KAuthorization.cv()},2,230)) goto _0;
			lauthorizationValue=lhttpHeaderValues__at.arrayElem(t9.get()).get();
		}
_3:
		Res<Bool>(outResult)=Bool(1).get();
		{
			Obj t11;
			c.f.fLine=42;
			if (g->Call(ctx,(PCV[]){t11.cv()},0,1482)) goto _0;
			Variant t12;
			if (g->GetMember(ctx,t11.cv(),KWeb__Users.cv(),t12.cv())) goto _0;
			Variant t13;
			if (g->Call(ctx,(PCV[]){t13.cv(),t12.cv(),Kquery.cv(),kmyjgtiEnStc.cv(),Parm<Txt>(inParams,inNbParam,1).cv(),lauthorizationValue.cv()},5,1498)) goto _0;
			g->Check(ctx);
			Variant t14;
			if (g->Call(ctx,(PCV[]){t14.cv(),t13.cv(),Kfirst.cv()},2,1498)) goto _0;
			Obj t15;
			if (!g->GetValue(ctx,(PCV[]){t15.cv(),t14.cv(),nullptr})) goto _0;
			lwebUser__e=t15.get();
		}
		{
			Bool t16;
			t16=!lwebUser__e.isNull();
			if (!(t16.get())) goto _4;
		}
		goto _0;
		goto _5;
_4:
		{
			Col t17;
			c.f.fLine=48;
			if (g->Call(ctx,(PCV[]){t17.cv()},0,1472)) goto _0;
			g->Check(ctx);
			lallowedAuthentications__c=t17.get();
		}
		lNOT__FOUND=-1;
		{
			Ref t18;
			t18.setLocalRef(ctx,lencodedUser.cv());
			c.f.fLine=51;
			if (g->Call(ctx,(PCV[]){nullptr,kDMtTBwwOQgY.cv(),t18.cv()},2,895)) goto _0;
			g->Check(ctx);
		}
		{
			Txt t19;
			g->AddString(KBasic_20.get(),lencodedUser.get(),t19.get());
			c.f.fLine=52;
			if (g->Call(ctx,(PCV[]){nullptr,lallowedAuthentications__c.cv(),Kpush.cv(),t19.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t20;
			t20.setLocalRef(ctx,lencodedUser.cv());
			c.f.fLine=54;
			if (g->Call(ctx,(PCV[]){nullptr,Kdemo_3Ademo.cv(),t20.cv()},2,895)) goto _0;
			g->Check(ctx);
		}
		{
			Txt t21;
			g->AddString(KBasic_20.get(),lencodedUser.get(),t21.get());
			c.f.fLine=55;
			if (g->Call(ctx,(PCV[]){nullptr,lallowedAuthentications__c.cv(),Kpush.cv(),t21.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Variant t22;
			c.f.fLine=57;
			if (g->Call(ctx,(PCV[]){t22.cv(),lallowedAuthentications__c.cv(),KindexOf.cv(),lauthorizationValue.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Bool t23;
			if (g->OperationOnAny(ctx,6,t22.cv(),lNOT__FOUND.cv(),t23.cv())) goto _0;
			if (!(t23.get())) goto _6;
		}
		Res<Bool>(outResult)=Bool(0).get();
		goto _7;
_6:
		Res<Bool>(outResult)=Bool(1).get();
_7:
		goto _0;
_5:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
