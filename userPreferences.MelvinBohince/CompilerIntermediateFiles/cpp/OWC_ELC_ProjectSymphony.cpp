extern int32_t vOK;
extern Txt K200_20OK;
extern Txt K401_20Bad_20Request;
extern Txt K402_20Bad_20Request;
extern Txt K403_20Bad_20Request;
extern Txt K441;
extern Txt K442;
extern Txt K443;
extern Txt K550;
extern Txt KContent_2DLength;
extern Txt KContent_2DType;
extern Txt KX_2DMETHOD;
extern Txt KX_2DURL;
extern Txt K_20;
extern Txt KpayloadID;
extern Txt kWFdzut0i53w;
extern Txt kYFjx1QhOaCU;
Asm4d_Proc proc_INBOXSYNCTOAMS;
Asm4d_Proc proc_OWC__SAVETOAMS;
Asm4d_Proc proc_OWC__SAVETOINBOX;
Asm4d_Proc proc_OWC__SETRESPONSE;
extern unsigned char D_proc_OWC__ELC__PROJECTSYMPHONY[];
void proc_OWC__ELC__PROJECTSYMPHONY( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__ELC__PROJECTSYMPHONY);
	if (!ctx->doingAbort) try {
		Txt lpayloadID__t;
		Bool lremoteSuccess;
		Blb lrequestBody__blob;
		Txt lbody;
		Long linbox__pkid;
		Txt lpathValue;
		Long lexpectedBodyLength__i;
		Long lactualBodyLength;
		Long lXML__PARSE__FAILURE;
		Txt lEXPECTED__CONTENT__TYPE;
		Txt lxmlRef__t;
		new ( outResult) Txt();
		Res<Txt>(outResult)=K200_20OK.get();
		lEXPECTED__CONTENT__TYPE=kYFjx1QhOaCU.get();
		lXML__PARSE__FAILURE=0;
		{
			Variant t0;
			c.f.fLine=23;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KContent_2DType.cv(),t0.cv())) goto _0;
			Bool t1;
			if (g->OperationOnAny(ctx,7,t0.cv(),lEXPECTED__CONTENT__TYPE.cv(),t1.cv())) goto _0;
			if (!(t1.get())) goto _2;
		}
		{
			Txt t2;
			t2=K401_20Bad_20Request.get();
			Txt t3;
			t3=K441.get();
			Txt t4;
			c.f.fLine=24;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t3.cv(),t2.cv()},t4.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t4.get();
		}
		goto _0;
_2:
		{
			Variant t5;
			c.f.fLine=29;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KContent_2DLength.cv(),t5.cv())) goto _0;
			Num t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv()},1,11)) goto _0;
			lexpectedBodyLength__i=(sLONG)lrint(t6.get());
		}
		{
			Ref t8;
			t8.setLocalRef(ctx,lrequestBody__blob.cv());
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){nullptr,t8.cv()},1,814)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t9;
			t9.setLocalRef(ctx,lrequestBody__blob.cv());
			Long t10;
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){t10.cv(),t9.cv()},1,605)) goto _0;
			lactualBodyLength=t10.get();
		}
		if (lactualBodyLength.get()==lexpectedBodyLength__i.get()) goto _3;
		{
			Txt t12;
			t12=K402_20Bad_20Request.get();
			Txt t13;
			t13=K442.get();
			Txt t14;
			c.f.fLine=36;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t13.cv(),t12.cv()},t14.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t14.get();
		}
		goto _0;
_3:
		{
			Ref t15;
			t15.setLocalRef(ctx,lrequestBody__blob.cv());
			Txt t16;
			c.f.fLine=42;
			if (g->Call(ctx,(PCV[]){t16.cv(),t15.cv(),Long(6).cv()},2,555)) goto _0;
			g->Check(ctx);
			lbody=t16.get();
		}
		{
			Ref t17;
			t17.setLocalRef(ctx,lbody.cv());
			Txt t18;
			c.f.fLine=45;
			if (g->Call(ctx,(PCV[]){t18.cv(),t17.cv()},1,720)) goto _0;
			g->Check(ctx);
			lxmlRef__t=t18.get();
		}
		if (0!=Var<Long>(ctx,vOK).get()) goto _4;
		{
			Txt t20;
			t20=K403_20Bad_20Request.get();
			Txt t21;
			t21=K443.get();
			Txt t22;
			c.f.fLine=47;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t21.cv(),t20.cv()},t22.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t22.get();
		}
		goto _0;
_4:
		{
			Ref t23;
			t23.setLocalRef(ctx,lpayloadID__t.cv());
			c.f.fLine=51;
			if (g->Call(ctx,(PCV[]){nullptr,lxmlRef__t.cv(),KpayloadID.cv(),t23.cv()},3,728)) goto _0;
			g->Check(ctx);
		}
		{
			Variant t24;
			c.f.fLine=56;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KX_2DMETHOD.cv(),t24.cv())) goto _0;
			Variant t25;
			if (g->OperationOnAny(ctx,0,t24.cv(),K_20.cv(),t25.cv())) goto _0;
			Variant t26;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KX_2DURL.cv(),t26.cv())) goto _0;
			Variant t27;
			if (g->OperationOnAny(ctx,0,t25.cv(),t26.cv(),t27.cv())) goto _0;
			Txt t28;
			if (!g->GetValue(ctx,(PCV[]){t28.cv(),t27.cv(),nullptr})) goto _0;
			lpathValue=t28.get();
		}
		{
			Ptr t29;
			t29.adopt(g->CreatePointerLocal(ctx,lbody.cv(),-1,-1));
			Txt t30;
			t30=lpayloadID__t.get();
			Txt t31;
			t31=lpathValue.get();
			Long t32;
			c.f.fLine=57;
			proc_OWC__SAVETOINBOX(glob,ctx,3,3,(PCV[]){t31.cv(),t30.cv(),t29.cv()},t32.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			linbox__pkid=t32.get();
		}
		if (0>=linbox__pkid.get()) goto _5;
		{
			Obj t34;
			Long t35;
			t35=linbox__pkid.get();
			Bool t36;
			c.f.fLine=60;
			proc_OWC__SAVETOAMS(glob,ctx,1,2,(PCV[]){t35.cv(),t34.cv()},t36.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lremoteSuccess=t36.get();
		}
		{
			Bool t37;
			t37=lremoteSuccess.get();
			Bool t38;
			t38=!(t37.get());
			if (!(t38.get())) goto _6;
		}
		{
			Bool t39;
			c.f.fLine=64;
			proc_INBOXSYNCTOAMS(glob,ctx,0,0,nullptr,t39.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
		}
_6:
		goto _7;
_5:
		{
			Txt t40;
			t40=kWFdzut0i53w.get();
			Txt t41;
			t41=K550.get();
			Txt t42;
			c.f.fLine=68;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t41.cv(),t40.cv()},t42.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t42.get();
		}
_7:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
