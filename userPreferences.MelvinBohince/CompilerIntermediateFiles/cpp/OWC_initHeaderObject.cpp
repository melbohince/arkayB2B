extern unsigned char D_proc_OWC__INITHEADEROBJECT[];
void proc_OWC__INITHEADEROBJECT( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_OWC__INITHEADEROBJECT);
	if (!ctx->doingAbort) try {
		Long v0;
		Long v1;
		Value_array_text lhttpHeaderValues__at;
		Long li;
		Value_array_text lhttpHeaderNames__at;
		new ( outResult) Obj();
		{
			Ref t0;
			t0.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t1;
			t1.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			c.f.fLine=23;
			if (g->Call(ctx,(PCV[]){nullptr,t1.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t2;
			t2.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			Ref t3;
			t3.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=25;
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),t2.cv()},2,697)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t4;
			c.f.fLine=28;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1471)) goto _0;
			g->Check(ctx);
			Res<Obj>(outResult)=t4.get();
		}
		li=1;
		{
			Ref t5;
			t5.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			Long t6;
			c.f.fLine=30;
			if (g->Call(ctx,(PCV[]){t6.cv(),t5.cv()},1,274)) goto _0;
			v0=t6.get();
		}
		goto _2;
_4:
		{
			Txt t7;
			t7=lhttpHeaderValues__at.arrayElem(li.get()).get();
			Txt t8;
			t8=t7.get();
			Txt t9;
			t9=lhttpHeaderNames__at.arrayElem(li.get()).get();
			Txt t10;
			t10=t9.get();
			c.f.fLine=31;
			if (g->Call(ctx,(PCV[]){nullptr,Res<Obj>(outResult).cv(),t10.cv(),t8.cv()},3,1497)) goto _0;
			g->Check(ctx);
		}
_3:
		li=li.get()+1;
_2:
		if (li.get()<=v0.get()) goto _4;
_5:
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
