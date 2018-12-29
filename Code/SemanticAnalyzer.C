/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "SemanticAnalyzer.H"



void SemanticAnalyzer::visitProgram(Program* t) {} //abstract class
void SemanticAnalyzer::visitTopDef(TopDef* t) {} //abstract class
void SemanticAnalyzer::visitArg(Arg* t) {} //abstract class
void SemanticAnalyzer::visitClsElems(ClsElems* t) {} //abstract class
void SemanticAnalyzer::visitBlock(Block* t) {} //abstract class
void SemanticAnalyzer::visitStmt(Stmt* t) {} //abstract class
void SemanticAnalyzer::visitItem(Item* t) {} //abstract class
void SemanticAnalyzer::visitBasicType(BasicType* t) {} //abstract class
void SemanticAnalyzer::visitTypeName(TypeName* t) {} //abstract class
void SemanticAnalyzer::visitType(Type* t) {} //abstract class
void SemanticAnalyzer::visitExpr(Expr* t) {} //abstract class
void SemanticAnalyzer::visitAddOp(AddOp* t) {} //abstract class
void SemanticAnalyzer::visitMulOp(MulOp* t) {} //abstract class
void SemanticAnalyzer::visitRelOp(RelOp* t) {} //abstract class


void SemanticAnalyzer::analyze(Visitable* v) {}

void SemanticAnalyzer::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listtopdef_->accept(this);

}

void SemanticAnalyzer::visitFnDef(FnDef *fndef)
{
  /* Code For FnDef Goes Here */

  fndef->type_->accept(this);
  visitIdent(fndef->ident_);
  fndef->listarg_->accept(this);
  fndef->block_->accept(this);

}

void SemanticAnalyzer::visitClsDef(ClsDef *clsdef)
{
  /* Code For ClsDef Goes Here */

  visitIdent(clsdef->ident_);
  clsdef->listclselems_->accept(this);

}

void SemanticAnalyzer::visitExtClsDef(ExtClsDef *extclsdef)
{
  /* Code For ExtClsDef Goes Here */

  visitIdent(extclsdef->ident_1);
  visitIdent(extclsdef->ident_2);
  extclsdef->listclselems_->accept(this);

}

void SemanticAnalyzer::visitAr(Ar *ar)
{
  /* Code For Ar Goes Here */

  ar->type_->accept(this);
  visitIdent(ar->ident_);

}

void SemanticAnalyzer::visitClsMethod(ClsMethod *clsmethod)
{
  /* Code For ClsMethod Goes Here */

  clsmethod->type_->accept(this);
  visitIdent(clsmethod->ident_);
  clsmethod->listarg_->accept(this);
  clsmethod->block_->accept(this);

}

void SemanticAnalyzer::visitClsField(ClsField *clsfield)
{
  /* Code For ClsField Goes Here */

  clsfield->type_->accept(this);
  visitIdent(clsfield->ident_);

}

void SemanticAnalyzer::visitBlk(Blk *blk)
{
  /* Code For Blk Goes Here */

  blk->liststmt_->accept(this);

}

void SemanticAnalyzer::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void SemanticAnalyzer::visitBStmt(BStmt *bstmt)
{
  /* Code For BStmt Goes Here */

  bstmt->block_->accept(this);

}

void SemanticAnalyzer::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */

  decl->type_->accept(this);
  decl->listitem_->accept(this);

}

void SemanticAnalyzer::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */

  visitIdent(ass->ident_);
  ass->expr_->accept(this);

}

void SemanticAnalyzer::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */

  visitIdent(incr->ident_);

}

void SemanticAnalyzer::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */

  visitIdent(decr->ident_);

}

void SemanticAnalyzer::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */

  ret->expr_->accept(this);

}

void SemanticAnalyzer::visitVRet(VRet *vret)
{
  /* Code For VRet Goes Here */


}

void SemanticAnalyzer::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */

  cond->expr_->accept(this);
  cond->stmt_->accept(this);

}

void SemanticAnalyzer::visitCondElse(CondElse *condelse)
{
  /* Code For CondElse Goes Here */

  condelse->expr_->accept(this);
  condelse->stmt_1->accept(this);
  condelse->stmt_2->accept(this);

}

void SemanticAnalyzer::visitWhile(While *w)
{
  /* Code For While Goes Here */

  w->expr_->accept(this);
  w->stmt_->accept(this);

}

void SemanticAnalyzer::visitFor(For *f)
{
  /* Code For For Goes Here */

  f->type_->accept(this);
  visitIdent(f->ident_1);
  visitIdent(f->ident_2);
  f->stmt_->accept(this);

}

void SemanticAnalyzer::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->expr_->accept(this);

}

void SemanticAnalyzer::visitNoInit(NoInit *noinit)
{
  /* Code For NoInit Goes Here */

  visitIdent(noinit->ident_);

}

void SemanticAnalyzer::visitInit(Init *init)
{
  /* Code For Init Goes Here */

  visitIdent(init->ident_);
  init->expr_->accept(this);

}

void SemanticAnalyzer::visitInt(Int *i)
{
  /* Code For Int Goes Here */


}

void SemanticAnalyzer::visitStr(Str *str)
{
  /* Code For Str Goes Here */


}

void SemanticAnalyzer::visitBool(Bool *b)
{
  /* Code For Bool Goes Here */


}

void SemanticAnalyzer::visitVoid(Void *v)
{
  /* Code For Void Goes Here */


}

void SemanticAnalyzer::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void SemanticAnalyzer::visitBType(BType *btype)
{
  /* Code For BType Goes Here */

  btype->basictype_->accept(this);

}

void SemanticAnalyzer::visitClsType(ClsType *clstype)
{
  /* Code For ClsType Goes Here */

  visitIdent(clstype->ident_);

}

void SemanticAnalyzer::visitArrayType(ArrayType *arraytype)
{
  /* Code For ArrayType Goes Here */

  arraytype->typename_->accept(this);

}

void SemanticAnalyzer::visitNormalType(NormalType *normaltype)
{
  /* Code For NormalType Goes Here */

  normaltype->typename_->accept(this);

}

void SemanticAnalyzer::visitEAttr(EAttr *eattr)
{
  /* Code For EAttr Goes Here */

  eattr->expr_->accept(this);
  visitIdent(eattr->ident_);

}

void SemanticAnalyzer::visitEMetCall(EMetCall *emetcall)
{
  /* Code For EMetCall Goes Here */

  emetcall->expr_->accept(this);
  visitIdent(emetcall->ident_);
  emetcall->listexpr_->accept(this);

}

void SemanticAnalyzer::visitECastNull(ECastNull *ecastnull)
{
  /* Code For ECastNull Goes Here */

  ecastnull->type_->accept(this);

}

void SemanticAnalyzer::visitEAt(EAt *eat)
{
  /* Code For EAt Goes Here */

  eat->expr_1->accept(this);
  eat->expr_2->accept(this);

}

void SemanticAnalyzer::visitENewArr(ENewArr *enewarr)
{
  /* Code For ENewArr Goes Here */

  enewarr->typename_->accept(this);
  enewarr->expr_->accept(this);

}

void SemanticAnalyzer::visitENewCls(ENewCls *enewcls)
{
  /* Code For ENewCls Goes Here */

  visitIdent(enewcls->ident_);

}

void SemanticAnalyzer::visitEVar(EVar *evar)
{
  /* Code For EVar Goes Here */

  visitIdent(evar->ident_);

}

void SemanticAnalyzer::visitELitInt(ELitInt *elitint)
{
  /* Code For ELitInt Goes Here */

  visitInteger(elitint->integer_);

}

void SemanticAnalyzer::visitELitTrue(ELitTrue *elittrue)
{
  /* Code For ELitTrue Goes Here */


}

void SemanticAnalyzer::visitELitFalse(ELitFalse *elitfalse)
{
  /* Code For ELitFalse Goes Here */


}

void SemanticAnalyzer::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  visitIdent(eapp->ident_);
  eapp->listexpr_->accept(this);

}

void SemanticAnalyzer::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);

}

void SemanticAnalyzer::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  neg->expr_->accept(this);

}

void SemanticAnalyzer::visitNot(Not *n)
{
  /* Code For Not Goes Here */

  n->expr_->accept(this);

}

void SemanticAnalyzer::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->expr_1->accept(this);
  emul->mulop_->accept(this);
  emul->expr_2->accept(this);

}

void SemanticAnalyzer::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->expr_1->accept(this);
  eadd->addop_->accept(this);
  eadd->expr_2->accept(this);

}

void SemanticAnalyzer::visitERel(ERel *erel)
{
  /* Code For ERel Goes Here */

  erel->expr_1->accept(this);
  erel->relop_->accept(this);
  erel->expr_2->accept(this);

}

void SemanticAnalyzer::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->expr_1->accept(this);
  eand->expr_2->accept(this);

}

void SemanticAnalyzer::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->expr_1->accept(this);
  eor->expr_2->accept(this);

}

void SemanticAnalyzer::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void SemanticAnalyzer::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void SemanticAnalyzer::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void SemanticAnalyzer::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void SemanticAnalyzer::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void SemanticAnalyzer::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void SemanticAnalyzer::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void SemanticAnalyzer::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void SemanticAnalyzer::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void SemanticAnalyzer::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void SemanticAnalyzer::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void SemanticAnalyzer::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListClsElems(ListClsElems* listclselems)
{
  for (ListClsElems::iterator i = listclselems->begin() ; i != listclselems->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListStmt(ListStmt* liststmt)
{
  for (ListStmt::iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListItem(ListItem* listitem)
{
  for (ListItem::iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListType(ListType* listtype)
{
  for (ListType::iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void SemanticAnalyzer::visitListExpr(ListExpr* listexpr)
{
  for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void SemanticAnalyzer::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void SemanticAnalyzer::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void SemanticAnalyzer::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void SemanticAnalyzer::visitString(String x)
{
  /* Code for String Goes Here */
}

void SemanticAnalyzer::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



