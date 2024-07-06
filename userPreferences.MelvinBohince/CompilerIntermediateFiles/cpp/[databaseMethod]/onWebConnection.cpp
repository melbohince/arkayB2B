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
			Obj t1;
			c.f.fLine=24;
			proc_OWC__INITRESPONSEOBJECT(glob,ctx,0,0,nullptr,t1.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresponse__o=t1.get();
		}
		{
			Variant t2;
			c.f.fLine=28;
			if (g->GetMember(ctx,lheader__o.cv(),KX_2DURL.cv(),t2.cv())) goto _0;
			Bool t3;
			if (g->OperationOnAny(ctx,6,t2.cv(),K_2FELCAriba_2F.cv(),t3.cv())) goto _0;
			Bool t4;
			t4=t3.get();
			if (!(t3.get())) goto _3;
			{
				Variant t5;
				if (g->GetMember(ctx,lheader__o.cv(),KX_2DMETHOD.cv(),t5.cv())) goto _0;
				Bool t6;
				if (g->OperationOnAny(ctx,6,t5.cv(),KPOST.cv(),t6.cv())) goto _0;
				t4=t6.get();
			}
_3:
			if (!(t4.get())) goto _4;
		}
		{
			Obj t7;
			t7=lheader__o.get();
			Txt t8;
			c.f.fLine=31;
			proc_OWC__ELC__PROJECTSYMPHONY(glob,ctx,1,1,(PCV[]){t7.cv()},t8.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresult__t=t8.get();
		}
		{
			Txt t9;
			c.f.fLine=33;
			proc_OWC__SENDRESPONSE(glob,ctx,0,0,nullptr,t9.cv());
			if (ctx->checkPendingErrors) g->CheckErr(ctx,0);
			if (ctx->doingAbort) goto _0;
			lresponse=t9.get();
		}
		goto _2;
_4:
_2:
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
