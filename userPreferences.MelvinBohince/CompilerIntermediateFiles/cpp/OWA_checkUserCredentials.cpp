extern Txt KAuthorization;
extern Txt KBasic_20;
extern Txt Kdemo_3Ademo;
extern Txt KindexOf;
extern Txt Kpush;
extern Txt kDMtTBwwOQgY;
extern unsigned char D_proc_OWA__CHECKUSERCREDENTIALS[];
void proc_OWA__CHECKUSERCREDENTIALS( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWA__CHECKUSERCREDENTIALS);
	if (!ctx->doingAbort) try {
		Long lNOT__FOUND;
		Txt lauthorizationValue;
		Value_array_text lhttpHeaderValues__at;
		Txt lencodedUser;
		Col lallowedAuthentications__c;
		Value_array_text lhttpHeaderNames__at;
		new ( outResult) Bool();
		{
			Col t0;
			c.f.fLine=20;
			if (g->Call(ctx,(PCV[]){t0.cv()},0,1472)) goto _0;
			g->Check(ctx);
			lallowedAuthentications__c=t0.get();
		}
		lNOT__FOUND=-1;
		{
			Ref t1;
			t1.setLocalRef(ctx,lencodedUser.cv());
			c.f.fLine=26;
			if (g->Call(ctx,(PCV[]){nullptr,kDMtTBwwOQgY.cv(),t1.cv()},2,895)) goto _0;
			g->Check(ctx);
		}
		{
			Txt t2;
			g->AddString(KBasic_20.get(),lencodedUser.get(),t2.get());
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){nullptr,lallowedAuthentications__c.cv(),Kpush.cv(),t2.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t3;
			t3.setLocalRef(ctx,lencodedUser.cv());
			c.f.fLine=29;
			if (g->Call(ctx,(PCV[]){nullptr,Kdemo_3Ademo.cv(),t3.cv()},2,895)) goto _0;
			g->Check(ctx);
		}
		{
			Txt t4;
			g->AddString(KBasic_20.get(),lencodedUser.get(),t4.get());
			c.f.fLine=30;
			if (g->Call(ctx,(PCV[]){nullptr,lallowedAuthentications__c.cv(),Kpush.cv(),t4.cv()},3,1500)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t5;
			t5.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){nullptr,t5.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t6;
			t6.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			c.f.fLine=34;
			if (g->Call(ctx,(PCV[]){nullptr,t6.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t7;
			t7.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			Ref t8;
			t8.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=36;
			if (g->Call(ctx,(PCV[]){nullptr,t8.cv(),t7.cv()},2,697)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t9;
			t9.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			Long t10;
			c.f.fLine=37;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv(),KAuthorization.cv()},2,230)) goto _0;
			lauthorizationValue=lhttpHeaderValues__at.arrayElem(t10.get()).get();
		}
		{
			Variant t12;
			c.f.fLine=39;
			if (g->Call(ctx,(PCV[]){t12.cv(),lallowedAuthentications__c.cv(),KindexOf.cv(),lauthorizationValue.cv()},3,1498)) goto _0;
			g->Check(ctx);
			Bool t13;
			if (g->OperationOnAny(ctx,6,t12.cv(),lNOT__FOUND.cv(),t13.cv())) goto _0;
			if (!(t13.get())) goto _2;
		}
		Res<Bool>(outResult)=Bool(0).get();
		goto _3;
_2:
		Res<Bool>(outResult)=Bool(1).get();
_3:
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
