extern Txt Kheader__o;
extern Txt Kstorage;
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
		Obj l__4D__auto__mutex__0;
		Obj l__4D__auto__mutex__1;
		new ( outResult) Obj();
		{
			Ref t0;
			t0.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=21;
			if (g->Call(ctx,(PCV[]){nullptr,t0.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t1;
			t1.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			c.f.fLine=22;
			if (g->Call(ctx,(PCV[]){nullptr,t1.cv(),Long(0).cv()},2,222)) goto _0;
		}
		{
			Ref t2;
			t2.setLocalRef(ctx,lhttpHeaderValues__at.cv());
			Ref t3;
			t3.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			c.f.fLine=24;
			if (g->Call(ctx,(PCV[]){nullptr,t3.cv(),t2.cv()},2,697)) goto _0;
			g->Check(ctx);
		}
		{
			Obj t4;
			c.f.fLine=27;
			if (g->Call(ctx,(PCV[]){t4.cv()},0,1526)) goto _0;
			g->Check(ctx);
			Res<Obj>(outResult)=t4.get();
		}
		{
			Obj t5;
			c.f.fLine=28;
			if (g->Call(ctx,(PCV[]){t5.cv(),Res<Obj>(outResult).cv()},1,1529)) goto _0;
			g->Check(ctx);
			l__4D__auto__mutex__0=t5.get();
		}
		li=1;
		{
			Ref t6;
			t6.setLocalRef(ctx,lhttpHeaderNames__at.cv());
			Long t7;
			c.f.fLine=31;
			if (g->Call(ctx,(PCV[]){t7.cv(),t6.cv()},1,274)) goto _0;
			v0=t7.get();
		}
		goto _2;
_4:
		{
			Txt t8;
			t8=lhttpHeaderValues__at.arrayElem(li.get()).get();
			Txt t9;
			t9=t8.get();
			Txt t10;
			t10=lhttpHeaderNames__at.arrayElem(li.get()).get();
			Txt t11;
			t11=t10.get();
			c.f.fLine=32;
			if (g->Call(ctx,(PCV[]){nullptr,Res<Obj>(outResult).cv(),t11.cv(),t9.cv()},3,1497)) goto _0;
			g->Check(ctx);
		}
_3:
		li=li.get()+1;
_2:
		if (li.get()<=v0.get()) goto _4;
_5:
		{
			Obj t14;
			l__4D__auto__mutex__0=t14.get();
		}
		{
			Obj t15;
			c.f.fLine=37;
			if (g->Call(ctx,(PCV[]){t15.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t16;
			if (g->GetMember(ctx,t15.cv(),Kstorage.cv(),t16.cv())) goto _0;
			Obj t17;
			if (g->Call(ctx,(PCV[]){t17.cv(),t16.cv()},1,1529)) goto _0;
			l__4D__auto__mutex__1=t17.get();
		}
		{
			Obj t18;
			c.f.fLine=38;
			if (g->Call(ctx,(PCV[]){t18.cv()},0,1714)) goto _0;
			g->Check(ctx);
			Variant t19;
			if (g->GetMember(ctx,t18.cv(),Kstorage.cv(),t19.cv())) goto _0;
			if (g->SetMember(ctx,t19.cv(),Kheader__o.cv(),Res<Obj>(outResult).cv())) goto _0;
		}
		{
			Obj t20;
			l__4D__auto__mutex__1=t20.get();
		}
		goto _0;
_0:
_1:
;
	} catch( Asm4d_error e) { g->Error( ctx, e); }

}
