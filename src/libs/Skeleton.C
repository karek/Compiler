/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitTopDef(TopDef* t) {} //abstract class
void Skeleton::visitArg(Arg* t) {} //abstract class
void Skeleton::visitClsElems(ClsElems* t) {} //abstract class
void Skeleton::visitBlock(Block* t) {} //abstract class
void Skeleton::visitStmt(Stmt* t) {} //abstract class
void Skeleton::visitItem(Item* t) {} //abstract class
void Skeleton::visitBasicType(BasicType* t) {} //abstract class
void Skeleton::visitTypeName(TypeName* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class
void Skeleton::visitLVal(LVal* t) {} //abstract class
void Skeleton::visitExpr(Expr* t) {} //abstract class
void Skeleton::visitAddOp(AddOp* t) {} //abstract class
void Skeleton::visitMulOp(MulOp* t) {} //abstract class
void Skeleton::visitRelOp(RelOp* t) {} //abstract class

void Skeleton::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listtopdef_->accept(this);

}

void Skeleton::visitFnDef(FnDef *fndef)
{
  /* Code For FnDef Goes Here */

  fndef->type_->accept(this);
  visitIdent(fndef->ident_);
  fndef->listarg_->accept(this);
  fndef->block_->accept(this);

}

void Skeleton::visitClsDef(ClsDef *clsdef)
{
  /* Code For ClsDef Goes Here */

  visitIdent(clsdef->ident_);
  clsdef->listclselems_->accept(this);

}

void Skeleton::visitExtClsDef(ExtClsDef *extclsdef)
{
  /* Code For ExtClsDef Goes Here */

  visitIdent(extclsdef->ident_1);
  visitIdent(extclsdef->ident_2);
  extclsdef->listclselems_->accept(this);

}

void Skeleton::visitAr(Ar *ar)
{
  /* Code For Ar Goes Here */

  ar->type_->accept(this);
  visitIdent(ar->ident_);

}

void Skeleton::visitClsMethod(ClsMethod *clsmethod)
{
  /* Code For ClsMethod Goes Here */

  clsmethod->type_->accept(this);
  visitIdent(clsmethod->ident_);
  clsmethod->listarg_->accept(this);
  clsmethod->block_->accept(this);

}

void Skeleton::visitClsField(ClsField *clsfield)
{
  /* Code For ClsField Goes Here */

  clsfield->type_->accept(this);
  visitIdent(clsfield->ident_);

}

void Skeleton::visitBlk(Blk *blk)
{
  /* Code For Blk Goes Here */

  blk->liststmt_->accept(this);

}

void Skeleton::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void Skeleton::visitBStmt(BStmt *bstmt)
{
  /* Code For BStmt Goes Here */

  bstmt->block_->accept(this);

}

void Skeleton::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */

  decl->type_->accept(this);
  decl->listitem_->accept(this);

}

void Skeleton::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */

  ass->lval_->accept(this);
  ass->expr_->accept(this);

}

void Skeleton::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */

  incr->lval_->accept(this);

}

void Skeleton::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */

  decr->lval_->accept(this);

}

void Skeleton::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */

  ret->expr_->accept(this);

}

void Skeleton::visitVRet(VRet *vret)
{
  /* Code For VRet Goes Here */


}

void Skeleton::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */

  cond->expr_->accept(this);
  cond->stmt_->accept(this);

}

void Skeleton::visitCondElse(CondElse *condelse)
{
  /* Code For CondElse Goes Here */

  condelse->expr_->accept(this);
  condelse->stmt_1->accept(this);
  condelse->stmt_2->accept(this);

}

void Skeleton::visitWhile(While *while)
{
  /* Code For While Goes Here */

  while->expr_->accept(this);
  while->stmt_->accept(this);

}

void Skeleton::visitFor(For *for)
{
  /* Code For For Goes Here */

  for->type_->accept(this);
  visitIdent(for->ident_1);
  visitIdent(for->ident_2);
  for->stmt_->accept(this);

}

void Skeleton::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->expr_->accept(this);

}

void Skeleton::visitNoInit(NoInit *noinit)
{
  /* Code For NoInit Goes Here */

  visitIdent(noinit->ident_);

}

void Skeleton::visitInit(Init *init)
{
  /* Code For Init Goes Here */

  visitIdent(init->ident_);
  init->expr_->accept(this);

}

void Skeleton::visitInt(Int *int)
{
  /* Code For Int Goes Here */


}

void Skeleton::visitStr(Str *str)
{
  /* Code For Str Goes Here */


}

void Skeleton::visitBool(Bool *bool)
{
  /* Code For Bool Goes Here */


}

void Skeleton::visitVoid(Void *void)
{
  /* Code For Void Goes Here */


}

void Skeleton::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void Skeleton::visitBType(BType *btype)
{
  /* Code For BType Goes Here */

  btype->basictype_->accept(this);

}

void Skeleton::visitClsType(ClsType *clstype)
{
  /* Code For ClsType Goes Here */

  visitIdent(clstype->ident_);

}

void Skeleton::visitArrayType(ArrayType *arraytype)
{
  /* Code For ArrayType Goes Here */

  arraytype->typename_->accept(this);

}

void Skeleton::visitNormalType(NormalType *normaltype)
{
  /* Code For NormalType Goes Here */

  normaltype->typename_->accept(this);

}

void Skeleton::visitLvVar(LvVar *lvvar)
{
  /* Code For LvVar Goes Here */

  visitIdent(lvvar->ident_);

}

void Skeleton::visitLvTab(LvTab *lvtab)
{
  /* Code For LvTab Goes Here */

  lvtab->expr_1->accept(this);
  lvtab->expr_2->accept(this);

}

void Skeleton::visitLvAttr(LvAttr *lvattr)
{
  /* Code For LvAttr Goes Here */

  lvattr->expr_->accept(this);
  visitIdent(lvattr->ident_);

}

void Skeleton::visitEAttr(EAttr *eattr)
{
  /* Code For EAttr Goes Here */

  eattr->expr_->accept(this);
  visitIdent(eattr->ident_);

}

void Skeleton::visitEMetCall(EMetCall *emetcall)
{
  /* Code For EMetCall Goes Here */

  emetcall->expr_->accept(this);
  visitIdent(emetcall->ident_);
  emetcall->listexpr_->accept(this);

}

void Skeleton::visitECastNull(ECastNull *ecastnull)
{
  /* Code For ECastNull Goes Here */

  visitIdent(ecastnull->ident_);

}

void Skeleton::visitEAt(EAt *eat)
{
  /* Code For EAt Goes Here */

  eat->expr_1->accept(this);
  eat->expr_2->accept(this);

}

void Skeleton::visitENewArr(ENewArr *enewarr)
{
  /* Code For ENewArr Goes Here */

  enewarr->basictype_->accept(this);
  enewarr->expr_->accept(this);

}

void Skeleton::visitENewClArr(ENewClArr *enewclarr)
{
  /* Code For ENewClArr Goes Here */

  visitIdent(enewclarr->ident_);
  enewclarr->expr_->accept(this);

}

void Skeleton::visitENewCls(ENewCls *enewcls)
{
  /* Code For ENewCls Goes Here */

  visitIdent(enewcls->ident_);

}

void Skeleton::visitEVar(EVar *evar)
{
  /* Code For EVar Goes Here */

  visitIdent(evar->ident_);

}

void Skeleton::visitELitInt(ELitInt *elitint)
{
  /* Code For ELitInt Goes Here */

  visitInteger(elitint->integer_);

}

void Skeleton::visitELitTrue(ELitTrue *elittrue)
{
  /* Code For ELitTrue Goes Here */


}

void Skeleton::visitELitFalse(ELitFalse *elitfalse)
{
  /* Code For ELitFalse Goes Here */


}

void Skeleton::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  visitIdent(eapp->ident_);
  eapp->listexpr_->accept(this);

}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);

}

void Skeleton::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  neg->expr_->accept(this);

}

void Skeleton::visitNot(Not *not)
{
  /* Code For Not Goes Here */

  not->expr_->accept(this);

}

void Skeleton::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->expr_1->accept(this);
  emul->mulop_->accept(this);
  emul->expr_2->accept(this);

}

void Skeleton::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->expr_1->accept(this);
  eadd->addop_->accept(this);
  eadd->expr_2->accept(this);

}

void Skeleton::visitERel(ERel *erel)
{
  /* Code For ERel Goes Here */

  erel->expr_1->accept(this);
  erel->relop_->accept(this);
  erel->expr_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->expr_1->accept(this);
  eand->expr_2->accept(this);

}

void Skeleton::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->expr_1->accept(this);
  eor->expr_2->accept(this);

}

void Skeleton::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void Skeleton::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void Skeleton::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void Skeleton::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void Skeleton::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void Skeleton::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void Skeleton::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void Skeleton::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void Skeleton::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void Skeleton::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void Skeleton::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void Skeleton::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListClsElems(ListClsElems* listclselems)
{
  for (ListClsElems::iterator i = listclselems->begin() ; i != listclselems->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStmt(ListStmt* liststmt)
{
  for (ListStmt::iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListItem(ListItem* listitem)
{
  for (ListItem::iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListType(ListType* listtype)
{
  for (ListType::iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExpr(ListExpr* listexpr)
{
  for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



