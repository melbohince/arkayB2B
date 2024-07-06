extern Txt KELCAriba;
extern Txt kVW_KfMAEXa8;
Asm4d_Proc proc_OWA__CHECKCLIENTWHITELIST;
Asm4d_Proc proc_OWA__CHECKUSERCREDENTIALS;
extern unsigned char D_db_8[];
void db_8( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_db_8);
	if (!ctx->doingAbort) try {
		Bool ldenied;
		new ( outResult) Bool();
		Res<Bool>(outResult)=Bool(1).get();
		ldenied=Bool(0).get();
		{
			Long t0;
			c.f.fLine=33;
			if (g->Call(ctx,(PCV[]){t0.cv(),KELCAriba.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},2,15)) goto _0;
			if (0>=t0.get()) goto _3;
		}
		{
			Txt t2;
			t2=KELCAriba.get();
			Txt t3;
			t3=Parm<Txt>(inParams,inNbParam,3).get();
			Bool t4;
			c.f.fLine=35;
			proc_OWA__CHECKCLIENTWHITELIST(glob,ctx,2,2,(PCV[]){t3.cv(),t2.cv()},t4.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Bool>(outResult)=t4.get();
		}
		{
			Bool t5;
			t5=Res<Bool>(outResult).get();
			Bool t6;
			t6=!(t5.get());
			if (!(t6.get())) goto _4;
		}
		Res<Bool>(outResult)=ldenied.get();
		goto _0;
_4:
		{
			Txt t7;
			t7=KELCAriba.get();
			Bool t8;
			c.f.fLine=40;
			proc_OWA__CHECKUSERCREDENTIALS(glob,ctx,1,1,(PCV[]){t7.cv()},t8.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			Res<Bool>(outResult)=t8.get();
		}
		{
			Bool t9;
			t9=Res<Bool>(outResult).get();
			Bool t10;
			t10=!(t9.get());
			if (!(t10.get())) goto _5;
		}
		Res<Bool>(outResult)=ldenied.get();
		goto _0;
_5:
		goto _0;
		goto _2;
_3:
		{
			Long t11;
			c.f.fLine=50;
			if (g->Call(ctx,(PCV[]){t11.cv(),kVW_KfMAEXa8.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},2,15)) goto _0;
			if (0>=t11.get()) goto _6;
		}
		goto _2;
_6:
		Res<Bool>(outResult)=ldenied.get();
		goto _0;
_2:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
