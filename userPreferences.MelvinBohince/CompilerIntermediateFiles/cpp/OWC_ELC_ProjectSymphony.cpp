extern int32_t vOK;
extern Txt K200_20OK;
extern Txt K401_20Bad_20Request;
extern Txt K402_20Bad_20Request;
extern Txt K403_20Bad_20Request;
extern Txt K441;
extern Txt K442;
extern Txt K443;
extern Txt K550;
extern Txt K551;
extern Txt KContent_2DLength;
extern Txt KContent_2DType;
extern Txt KX_2DMETHOD;
extern Txt KX_2DURL;
extern Txt K_20;
extern Txt kWFdzut0i53w;
extern Txt kYFjx1QhOaCU;
extern Txt kaQ$SxnkE$1o;
Asm4d_Proc proc_OWC__SAVETOAMS;
Asm4d_Proc proc_OWC__SAVETOINBOX;
Asm4d_Proc proc_OWC__SETRESPONSE;
extern unsigned char D_proc_OWC__ELC__PROJECTSYMPHONY[];
void proc_OWC__ELC__PROJECTSYMPHONY( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__ELC__PROJECTSYMPHONY);
	if (!ctx->doingAbort) try {
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
			c.f.fLine=22;
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
			c.f.fLine=28;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KContent_2DLength.cv(),t5.cv())) goto _0;
			Num t6;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv()},1,11)) goto _0;
			lexpectedBodyLength__i=(sLONG)lrint(t6.get());
		}
		{
			Ref t8;
			t8.setLocalRef(ctx,lrequestBody__blob.cv());
			c.f.fLine=31;
			if (g->Call(ctx,(PCV[]){nullptr,t8.cv()},1,814)) goto _0;
			g->Check(ctx);
		}
		{
			Ref t9;
			t9.setLocalRef(ctx,lrequestBody__blob.cv());
			Long t10;
			c.f.fLine=32;
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
			c.f.fLine=41;
			if (g->Call(ctx,(PCV[]){t16.cv(),t15.cv(),Long(6).cv()},2,555)) goto _0;
			g->Check(ctx);
			lbody=t16.get();
		}
		{
			Ref t17;
			t17.setLocalRef(ctx,lbody.cv());
			Txt t18;
			c.f.fLine=44;
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
			Variant t23;
			c.f.fLine=54;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KX_2DMETHOD.cv(),t23.cv())) goto _0;
			Variant t24;
			if (g->OperationOnAny(ctx,0,t23.cv(),K_20.cv(),t24.cv())) goto _0;
			Variant t25;
			if (g->GetMember(ctx,Parm<Obj>(inParams,inNbParam,1).cv(),KX_2DURL.cv(),t25.cv())) goto _0;
			Variant t26;
			if (g->OperationOnAny(ctx,0,t24.cv(),t25.cv(),t26.cv())) goto _0;
			Txt t27;
			if (!g->GetValue(ctx,(PCV[]){t27.cv(),t26.cv(),nullptr})) goto _0;
			lpathValue=t27.get();
		}
		{
			Ptr t28;
			t28.adopt(g->CreatePointerLocal(ctx,lbody.cv(),-1,-1));
			Txt t29;
			t29=lpathValue.get();
			Long t30;
			c.f.fLine=55;
			proc_OWC__SAVETOINBOX(glob,ctx,2,2,(PCV[]){t29.cv(),t28.cv()},t30.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			linbox__pkid=t30.get();
		}
		if (0>=linbox__pkid.get()) goto _5;
		{
			Long t32;
			t32=linbox__pkid.get();
			Bool t33;
			c.f.fLine=58;
			proc_OWC__SAVETOAMS(glob,ctx,1,1,(PCV[]){t32.cv()},t33.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lremoteSuccess=t33.get();
		}
		{
			Bool t34;
			t34=lremoteSuccess.get();
			Bool t35;
			t35=!(t34.get());
			if (!(t35.get())) goto _6;
		}
		{
			Txt t36;
			t36=kaQ$SxnkE$1o.get();
			Txt t37;
			t37=K551.get();
			Txt t38;
			c.f.fLine=61;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t37.cv(),t36.cv()},t38.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t38.get();
		}
_6:
		goto _7;
_5:
		{
			Txt t39;
			t39=kWFdzut0i53w.get();
			Txt t40;
			t40=K550.get();
			Txt t41;
			c.f.fLine=65;
			proc_OWC__SETRESPONSE(glob,ctx,2,2,(PCV[]){t40.cv(),t39.cv()},t41.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Txt>(outResult)=t41.get();
		}
_7:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
