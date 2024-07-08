extern Txt K200_20OK;
extern Txt KPOST;
extern Txt KX_2DMETHOD;
extern Txt KX_2DURL;
extern Txt K_2FELCAriba_2F;
Asm4d_Proc proc_OWC__ELC__PROJECTSYMPHONY;
Asm4d_Proc proc_OWC__INITHEADEROBJECT;
Asm4d_Proc proc_OWC__INITRESPONSEOBJECT;
Asm4d_Proc proc_OWC__SENDRESPONSE;
extern unsigned char D_db_6[];
void db_6( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_db_6);
	if (!ctx->doingAbort) try {
		Obj lresponse__o;
		Txt lresponse;
		Obj lheader__o;
		Txt lresult__t;
		{
			Obj t0;
			c.f.fLine=22;
			proc_OWC__INITHEADEROBJECT(glob,ctx,0,0,nullptr,t0.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lheader__o=t0.get();
		}
		{
			Txt t1;
			t1=K200_20OK.get();
			Obj t2;
			c.f.fLine=24;
			proc_OWC__INITRESPONSEOBJECT(glob,ctx,1,1,(PCV[]){t1.cv()},t2.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresponse__o=t2.get();
		}
		{
			Variant t3;
			c.f.fLine=31;
			if (g->GetMember(ctx,lheader__o.cv(),KX_2DURL.cv(),t3.cv())) goto _0;
			Bool t4;
			if (g->OperationOnAny(ctx,6,t3.cv(),K_2FELCAriba_2F.cv(),t4.cv())) goto _0;
			Bool t5;
			t5=t4.get();
			if (!(t4.get())) goto _3;
			{
				Variant t6;
				if (g->GetMember(ctx,lheader__o.cv(),KX_2DMETHOD.cv(),t6.cv())) goto _0;
				Bool t7;
				if (g->OperationOnAny(ctx,6,t6.cv(),KPOST.cv(),t7.cv())) goto _0;
				t5=t7.get();
			}
_3:
			if (!(t5.get())) goto _4;
		}
		{
			Obj t8;
			t8=lheader__o.get();
			Txt t9;
			c.f.fLine=34;
			proc_OWC__ELC__PROJECTSYMPHONY(glob,ctx,1,1,(PCV[]){t8.cv()},t9.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresult__t=t9.get();
		}
		{
			Txt t10;
			c.f.fLine=36;
			proc_OWC__SENDRESPONSE(glob,ctx,0,0,nullptr,t10.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresponse=t10.get();
		}
		goto _2;
_4:
_2:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
