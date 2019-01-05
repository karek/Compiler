/*** BNFC-Generated Visitor Design Pattern ReturnChecker. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "ReturnChecker.H"
#include <iostream>

using namespace std;



void ReturnChecker::visitProgram(Program* t) {} //abstract class
void ReturnChecker::visitTopDef(TopDef* t) {} //abstract class
void ReturnChecker::visitArg(Arg* t) {} //abstract class
void ReturnChecker::visitClsElems(ClsElems* t) {} //abstract class
void ReturnChecker::visitBlock(Block* t) {} //abstract class
void ReturnChecker::visitStmt(Stmt* t) {} //abstract class
void ReturnChecker::visitItem(Item* t) {} //abstract class
void ReturnChecker::visitBasicType(BasicType* t) {} //abstract class
void ReturnChecker::visitTypeName(TypeName* t) {} //abstract class
void ReturnChecker::visitType(Type* t) {} //abstract class
void ReturnChecker::visitLVal(LVal* t) {} //abstract class
void ReturnChecker::visitExpr(Expr* t) {} //abstract class
void ReturnChecker::visitAddOp(AddOp* t) {} //abstract class
void ReturnChecker::visitMulOp(MulOp* t) {} //abstract class
void ReturnChecker::visitRelOp(RelOp* t) {} //abstract class
 

void ReturnChecker::checkReturns(Visitable* v, Env* e) {
    env = e;
    v->accept(this);
}
 
void ReturnChecker::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listtopdef_->accept(this);

}

void ReturnChecker::visitFnDef(FnDef *fndef)
{
  /* Code For FnDef Goes Here */

  fndef->type_->accept(this);
  visitIdent(fndef->ident_);
  fndef->listarg_->accept(this);
  fndef->block_->accept(this);

}

void ReturnChecker::visitClsDef(ClsDef *clsdef)
{
  /* Code For ClsDef Goes Here */

  visitIdent(clsdef->ident_);
  clsdef->listclselems_->accept(this);

}

void ReturnChecker::visitExtClsDef(ExtClsDef *extclsdef)
{
  /* Code For ExtClsDef Goes Here */

  visitIdent(extclsdef->ident_1);
  visitIdent(extclsdef->ident_2);
  extclsdef->listclselems_->accept(this);

}

void ReturnChecker::visitAr(Ar *ar)
{
  /* Code For Ar Goes Here */

  ar->type_->accept(this);
  visitIdent(ar->ident_);

}

void ReturnChecker::visitClsMethod(ClsMethod *clsmethod)
{
  /* Code For ClsMethod Goes Here */

  clsmethod->type_->accept(this);
  visitIdent(clsmethod->ident_);
  clsmethod->listarg_->accept(this);
  clsmethod->block_->accept(this);

}

void ReturnChecker::visitClsField(ClsField *clsfield)
{
  /* Code For ClsField Goes Here */

  clsfield->type_->accept(this);
  visitIdent(clsfield->ident_);

}

void ReturnChecker::visitBlk(Blk *blk)
{
  /* Code For Blk Goes Here */

  blk->liststmt_->accept(this);

}

void ReturnChecker::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void ReturnChecker::visitBStmt(BStmt *bstmt)
{
  /* Code For BStmt Goes Here */

  bstmt->block_->accept(this);

}

void ReturnChecker::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */

  decl->type_->accept(this);
  decl->listitem_->accept(this);

}

void ReturnChecker::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */

  ass->lval_->accept(this);
  ass->expr_->accept(this);

}

void ReturnChecker::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */

  incr->lval_->accept(this);

}

void ReturnChecker::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */

  decr->lval_->accept(this);

}

void ReturnChecker::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */

  ret->expr_->accept(this);

}

void ReturnChecker::visitVRet(VRet *vret)
{
  /* Code For VRet Goes Here */


}

void ReturnChecker::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */

  cond->expr_->accept(this);
  cond->stmt_->accept(this);

}

void ReturnChecker::visitCondElse(CondElse *condelse)
{
  /* Code For CondElse Goes Here */

  condelse->expr_->accept(this);
  condelse->stmt_1->accept(this);
  condelse->stmt_2->accept(this);

}

void ReturnChecker::visitWhile(While *w)
{
  /* Code For While Goes Here */

  w->expr_->accept(this);
  w->stmt_->accept(this);

}

void ReturnChecker::visitFor(For *f)
{
  /* Code For For Goes Here */

  f->type_->accept(this);
  visitIdent(f->ident_1);
  visitIdent(f->ident_2);
  f->stmt_->accept(this);

}

void ReturnChecker::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->expr_->accept(this);

}

void ReturnChecker::visitNoInit(NoInit *noinit)
{
  /* Code For NoInit Goes Here */

  visitIdent(noinit->ident_);

}

void ReturnChecker::visitInit(Init *init)
{
  /* Code For Init Goes Here */

  visitIdent(init->ident_);
  init->expr_->accept(this);

}

void ReturnChecker::visitInt(Int *i)
{
  /* Code For Int Goes Here */


}

void ReturnChecker::visitStr(Str *str)
{
  /* Code For Str Goes Here */


}

void ReturnChecker::visitBool(Bool *b)
{
  /* Code For Bool Goes Here */


}

void ReturnChecker::visitVoid(Void *v)
{
  /* Code For Void Goes Here */


}

void ReturnChecker::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void ReturnChecker::visitBType(BType *btype)
{
  /* Code For BType Goes Here */

  btype->basictype_->accept(this);

}

void ReturnChecker::visitClsType(ClsType *clstype)
{
  /* Code For ClsType Goes Here */

  visitIdent(clstype->ident_);

}

void ReturnChecker::visitArrayType(ArrayType *arraytype)
{
  /* Code For ArrayType Goes Here */

  arraytype->typename_->accept(this);

}

void ReturnChecker::visitNormalType(NormalType *normaltype)
{
  /* Code For NormalType Goes Here */

  normaltype->typename_->accept(this);

}

void ReturnChecker::visitLvVar(LvVar *lvvar)
{
  /* Code For LvVar Goes Here */

  visitIdent(lvvar->ident_);

}

void ReturnChecker::visitLvTab(LvTab *lvtab)
{
  /* Code For LvTab Goes Here */

  lvtab->expr_1->accept(this);
  lvtab->expr_2->accept(this);

}

void ReturnChecker::visitLvAttr(LvAttr *lvattr)
{
  /* Code For LvAttr Goes Here */

  lvattr->expr_->accept(this);
  visitIdent(lvattr->ident_);

}

void ReturnChecker::visitEAttr(EAttr *eattr)
{
  /* Code For EAttr Goes Here */

  eattr->expr_->accept(this);
  visitIdent(eattr->ident_);

}

void ReturnChecker::visitEMetCall(EMetCall *emetcall)
{
  /* Code For EMetCall Goes Here */

  emetcall->expr_->accept(this);
  visitIdent(emetcall->ident_);
  emetcall->listexpr_->accept(this);

}

void ReturnChecker::visitECastNull(ECastNull *ecastnull)
{
  /* Code For ECastNull Goes Here */

  visitIdent(ecastnull->ident_);

}

void ReturnChecker::visitEAt(EAt *eat)
{
  /* Code For EAt Goes Here */

  eat->expr_1->accept(this);
  eat->expr_2->accept(this);

}

void ReturnChecker::visitENewArr(ENewArr *enewarr)
{
  /* Code For ENewArr Goes Here */

  enewarr->basictype_->accept(this);
  enewarr->expr_->accept(this);

}

void ReturnChecker::visitENewClArr(ENewClArr *enewclarr)
{
  /* Code For ENewClArr Goes Here */

  visitIdent(enewclarr->ident_);
  enewclarr->expr_->accept(this);

}

void ReturnChecker::visitENewCls(ENewCls *enewcls)
{
  /* Code For ENewCls Goes Here */

  visitIdent(enewcls->ident_);

}

void ReturnChecker::visitEVar(EVar *evar)
{
  /* Code For EVar Goes Here */

  visitIdent(evar->ident_);

}

void ReturnChecker::visitELitInt(ELitInt *elitint)
{
  /* Code For ELitInt Goes Here */

  visitInteger(elitint->integer_);

}

void ReturnChecker::visitELitTrue(ELitTrue *elittrue)
{
  /* Code For ELitTrue Goes Here */


}

void ReturnChecker::visitELitFalse(ELitFalse *elitfalse)
{
  /* Code For ELitFalse Goes Here */


}

void ReturnChecker::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  visitIdent(eapp->ident_);
  eapp->listexpr_->accept(this);

}

void ReturnChecker::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);

}

void ReturnChecker::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  neg->expr_->accept(this);

}

void ReturnChecker::visitNot(Not *n)
{
  /* Code For Not Goes Here */

  n->expr_->accept(this);

}

void ReturnChecker::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->expr_1->accept(this);
  emul->mulop_->accept(this);
  emul->expr_2->accept(this);

}

void ReturnChecker::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->expr_1->accept(this);
  eadd->addop_->accept(this);
  eadd->expr_2->accept(this);

}

void ReturnChecker::visitERel(ERel *erel)
{
  /* Code For ERel Goes Here */

  erel->expr_1->accept(this);
  erel->relop_->accept(this);
  erel->expr_2->accept(this);

}

void ReturnChecker::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->expr_1->accept(this);
  eand->expr_2->accept(this);

}

void ReturnChecker::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->expr_1->accept(this);
  eor->expr_2->accept(this);

}

void ReturnChecker::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void ReturnChecker::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void ReturnChecker::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void ReturnChecker::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void ReturnChecker::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void ReturnChecker::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void ReturnChecker::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void ReturnChecker::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void ReturnChecker::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void ReturnChecker::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void ReturnChecker::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void ReturnChecker::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListClsElems(ListClsElems* listclselems)
{
  for (ListClsElems::iterator i = listclselems->begin() ; i != listclselems->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListStmt(ListStmt* liststmt)
{
  for (ListStmt::iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListItem(ListItem* listitem)
{
  for (ListItem::iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListType(ListType* listtype)
{
  for (ListType::iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnChecker::visitListExpr(ListExpr* listexpr)
{
  for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void ReturnChecker::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void ReturnChecker::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void ReturnChecker::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void ReturnChecker::visitString(String x)
{
  /* Code for String Goes Here */
}

void ReturnChecker::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



