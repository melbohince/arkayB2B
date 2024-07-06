extern Txt K4D_20Server;
extern Txt KAddresses;
extern Txt Kams;
extern Txt Khostname;
extern Txt Ktype;
extern Txt k84caxgSqmhs;
extern unsigned char D_proc_AMS__OPEN__REMOTEDATASTORE[];
void proc_AMS__OPEN__REMOTEDATASTORE( Asm4d_globals *glob, tProcessGlobals *ctx, int32_t inNbExplicitParam, int32_t inNbParam, PCV inParams[], CV *outResult)
{
	CallChain c(ctx,D_proc_AMS__OPEN__REMOTEDATASTORE);
	if (!ctx->doingAbort) try {
		Obj lconnectTo;
		Txt llocalId;
		new ( outResult) Obj();
		{
			Long t0;
			t0=inNbExplicitParam;
			Bool t1;
			t1=1==t0.get();
			Txt t2;
			if (!(t1.get())) goto _2;
			{
				t2=Parm<Txt>(inParams,inNbParam,1).get();
				goto _3;
			}
_2:
			{
				t2=k84caxgSqmhs.get();
			}
_3:
			Parm<Txt>(inParams,inNbParam,1)=t2.get();
		}
		{
			Obj t4;
			c.f.fLine=18;
			if (g->Call(ctx,(PCV[]){t4.cv(),Ktype.cv(),K4D_20Server.cv(),Khostname.cv(),Parm<Txt>(inParams,inNbParam,1).cv()},4,1471)) goto _0;
			g->Check(ctx);
			lconnectTo=t4.get();
		}
		llocalId=Kams.get();
		{
			Obj t5;
			c.f.fLine=25;
			if (g->Call(ctx,(PCV[]){t5.cv(),lconnectTo.cv(),llocalId.cv()},2,1452)) goto _0;
			g->Check(ctx);
			Res<Obj>(outResult)=t5.get();
		}
		{
			Bool t6;
			t6=Res<Obj>(outResult).isNull();
			Bool t7;
			t7=t6.get();
			if (t6.get()) goto _4;
			{
				Col t8;
				c.f.fLine=29;
				if (g->Call(ctx,(PCV[]){t8.cv(),Res<Obj>(outResult).cv()},1,1719)) goto _0;
				g->Check(ctx);
				Variant t9;
				if (g->GetMember(ctx,t8.cv(),Long(0).cv(),t9.cv())) goto _0;
				Bool t10;
				if (g->OperationOnAny(ctx,7,t9.cv(),KAddresses.cv(),t10.cv())) goto _0;
				t7=t10.get();
			}
_4:
			if (!(t7.get())) goto _5;
		}
_5:
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
