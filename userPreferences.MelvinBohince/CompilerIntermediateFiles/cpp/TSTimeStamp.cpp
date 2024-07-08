extern unsigned char D_proc_TSTIMESTAMP[];
void proc_TSTIMESTAMP( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_TSTIMESTAMP);
	if (!ctx->doingAbort) try {
		Long lpc;
		new ( outResult) Variant();
		{
			Long t0;
			t0=inNbExplicitParam;
			lpc=t0.get();
		}
		if (0!=lpc.get()) goto _3;
		{
			Date t2;
			c.f.fLine=14;
			if (g->Call(ctx,(PCV[]){t2.cv()},0,33)) goto _0;
			Parm<Date>(inParams,inNbParam,1)=t2.get();
		}
		{
			Time t3;
			c.f.fLine=15;
			if (g->Call(ctx,(PCV[]){t3.cv()},0,178)) goto _0;
			Parm<Time>(inParams,inNbParam,2)=t3.get();
		}
		goto _2;
_3:
		if (1!=lpc.get()) goto _4;
		{
			Bool t5;
			t5=Parm<Date>(inParams,inNbParam,1).get()==Date(0,0,0).get();
			if (!(t5.get())) goto _5;
		}
		Parm<Date>(inParams,inNbParam,1)=Date(17,4,1995).get();
		goto _6;
_5:
		Parm<Date>(inParams,inNbParam,1)=Parm<Date>(inParams,inNbParam,1).get();
_6:
		{
			Time t6;
			c.f.fLine=23;
			if (g->Call(ctx,(PCV[]){t6.cv()},0,178)) goto _0;
			Parm<Time>(inParams,inNbParam,2)=t6.get();
		}
		goto _2;
_4:
		if (2!=lpc.get()) goto _7;
		{
			Bool t8;
			t8=Parm<Date>(inParams,inNbParam,1).get()==Date(0,0,0).get();
			if (!(t8.get())) goto _8;
		}
		Parm<Date>(inParams,inNbParam,1)=Date(17,4,1995).get();
_8:
		Parm<Time>(inParams,inNbParam,2)=Parm<Time>(inParams,inNbParam,2).get();
		goto _2;
_7:
_2:
		{
			Num t9;
			t9=g->SubstractDate(Parm<Date>(inParams,inNbParam,1).get(),Date(17,4,1995).get());
			Num t10;
			t10=t9.get()*86400;
			Long t11;
			t11=Parm<Time>(inParams,inNbParam,2).get()*1;
			Num t12;
			t12=t11.get();
			Num t13;
			t13=t10.get()+t12.get();
			c.f.fLine=33;
			if (!g->SetValue(ctx,(PCV[]){t13.cv(),Res<Variant>(outResult).cv(),nullptr})) goto _0;
		}
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
