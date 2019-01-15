/*** BNFC-Generated Visitor Design Pattern CodeCreator. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include <iostream>
#include <sstream>
#include "CodeCreator.H"

using namespace std;

void CodeCreator::visitProgram(Program *t) {}      // abstract class
void CodeCreator::visitTopDef(TopDef *t) {}        // abstract class
void CodeCreator::visitArg(Arg *t) {}              // abstract class
void CodeCreator::visitClsElems(ClsElems *t) {}    // abstract class
void CodeCreator::visitBlock(Block *t) {}          // abstract class
void CodeCreator::visitStmt(Stmt *t) {}            // abstract class
void CodeCreator::visitItem(Item *t) {}            // abstract class
void CodeCreator::visitBasicType(BasicType *t) {}  // abstract class
void CodeCreator::visitTypeName(TypeName *t) {}    // abstract class
void CodeCreator::visitType(Type *t) {}            // abstract class
void CodeCreator::visitLVal(LVal *t) {}            // abstract class
void CodeCreator::visitExpr(Expr *t) {}            // abstract class
void CodeCreator::visitAddOp(AddOp *t) {}          // abstract class
void CodeCreator::visitMulOp(MulOp *t) {}          // abstract class
void CodeCreator::visitRelOp(RelOp *t) {}          // abstract class

void CodeCreator::create(Visitable *v, Env *e) {
    env = e;
    genCode = true;
    env->resetLabNr();
    cerr << generateSections();
    v->accept(this);
}

string CodeCreator::generateSections() {
    stringstream ss;
    ss << ".data\n";

    for (int i = 0; i < env->getStrCnt(); i++) {
        ss << env->getLabStr(i) << ":\t"
           << ".string \"" << env->getString(i) << "\"\n";
    }

    ss << ".text\n";
    ss << ".globl main\n\n";
    return ss.str();
}

string CodeCreator::generateProgram() {
    stringstream ss;
    for (int i = 0; i < instructions.size(); i++) {
        if (!instructions[i]->isLabel())
            ss << "\t";
        ss << instructions[i]->toStr();
    }
    ss << "\n";

    return ss.str();
}

void CodeCreator::deleteInstr() {
    for (int i = 0; i < instructions.size(); i++) {
        delete instructions[i];
    }
    instructions.clear();
}

void CodeCreator::printAllInstrs() {
    for (int i = 0; i < instructions.size(); i++) {
        if (!instructions[i]->isLabel())
            cerr << "\t";
        cerr << instructions[i]->toStr();
    }
    cerr << "\n";
}

void CodeCreator::emit(Instruction *instr) {
    instructions.push_back(instr);
}

void CodeCreator::visitProg(Prog *prog) {
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);
}

void CodeCreator::visitFnDef(FnDef *fndef) {
    /* Code For FnDef Goes Here */
    curFunc = fndef->ident_;
    i = new Label(fndef->ident_, "  #funkcja");
    emit(i);
    i = new Push(Addr(Reg::EBP).toStr());
    emit(i);
    i = new Mov(Addr(Reg::ESP).toStr(), Addr(Reg::EBP).toStr());
    emit(i);

    stringstream ss;
    ss << "$" << env->getLocalsCnt(fndef->ident_) * MULTIPLIER;
    i = new Sub(ss.str(), Addr(Reg::ESP).toStr());
    emit(i);

    nrLoc = -1;
    fndef->type_->accept(this);
    visitIdent(fndef->ident_);
    fndef->listarg_->accept(this);

    vector<pair<string, TType>> fargs = env->getArgs(fndef->ident_);

    wasRet = false;
    env->beginBlock();  // Arguments vars
    for (int i = fargs.size() - 1; i >= 0; i--) {
        int pos = i + 2;
        env->addVarToCurScope(fargs[i].first, fargs[i].second, pos);
    }
    fndef->block_->accept(this);
    env->endBlock();

    if (!wasRet && env->getRetType(fndef->ident_).isVoid())
        emitRetSequence();
}

void CodeCreator::visitClsDef(ClsDef *clsdef) {
    /* Code For ClsDef Goes Here */

    visitIdent(clsdef->ident_);
    clsdef->listclselems_->accept(this);
}

void CodeCreator::visitExtClsDef(ExtClsDef *extclsdef) {
    /* Code For ExtClsDef Goes Here */

    visitIdent(extclsdef->ident_1);
    visitIdent(extclsdef->ident_2);
    extclsdef->listclselems_->accept(this);
}

void CodeCreator::visitAr(Ar *ar) {
    /* Code For Ar Goes Here */

    ar->type_->accept(this);
    visitIdent(ar->ident_);
}

void CodeCreator::visitClsMethod(ClsMethod *clsmethod) {
    /* Code For ClsMethod Goes Here */

    clsmethod->type_->accept(this);
    visitIdent(clsmethod->ident_);
    clsmethod->listarg_->accept(this);
    clsmethod->block_->accept(this);
}

void CodeCreator::visitClsField(ClsField *clsfield) {
    /* Code For ClsField Goes Here */

    clsfield->type_->accept(this);
    visitIdent(clsfield->ident_);
}

void CodeCreator::visitBlk(Blk *blk) {
    /* Code For Blk Goes Here */

    blk->liststmt_->accept(this);
}

void CodeCreator::visitEmpty(Empty *empty) {
    /* Code For Empty Goes Here */
}

void CodeCreator::visitBStmt(BStmt *bstmt) {
    /* Code For BStmt Goes Here */
    env->beginBlock();
    bstmt->block_->accept(this);
    env->endBlock();
}

void CodeCreator::visitDecl(Decl *decl) {
    /* Code For Decl Goes Here */

    decl->type_->accept(this);
    decl->listitem_->accept(this);
}

void CodeCreator::genStdTrueFalse(string tmp_lt, string tmp_lf, string tmp_ln) {
    lt = tmp_lt;
    lf = tmp_lf;
    ln = tmp_ln;
    i = new Label(lt, "   #lt");
    emit(i);
    i = new Push("$1");
    emit(i);
    i = new Jmp(ln);
    emit(i);

    i = new Label(lf, "   #lf");
    emit(i);
    i = new Push("$0");
    emit(i);

    i = new Label(ln, "   #ln");
    emit(i);
}

void CodeCreator::visitAss(Ass *ass) {
    /* Code For Ass Goes Here */

    genCode = false;
    ass->lval_->accept(this);  // Check the type of Var
    genCode = true;
    TType type = lastType;

    if (type.isBool()) {
        lt = env->getNextLabel();
        lf = env->getNextLabel();
        ln = env->getNextLabel();
    }
    string tmp_lt = lt, tmp_lf = lf, tmp_ln = ln;

    ass->expr_->accept(this);

    if (type.isBool()) {
        genStdTrueFalse(tmp_lt, tmp_lf, tmp_ln);
    }

    i = new Pop(Addr(Reg::ECX).toStr());
    emit(i);

    ass->lval_->accept(this);
    i = new Mov(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr(true));
    emit(i);
}

void CodeCreator::visitIncr(Incr *incr) {
    /* Code For Incr Goes Here */
    incr->lval_->accept(this);
    i = new Inc(Addr(Reg::EAX).toStr(true));
    emit(i);
}

void CodeCreator::visitDecr(Decr *decr) {
    /* Code For Decr Goes Here */
    decr->lval_->accept(this);
    i = new Dec(Addr(Reg::EAX).toStr(true));
    emit(i);
}

void CodeCreator::emitRetSequence() {
    i = new Mov(Addr(Reg::EBP).toStr(), Addr(Reg::ESP).toStr());
    emit(i);
    i = new Pop(Addr(Reg::EBP).toStr());
    emit(i);
    i = new RetC();
    emit(i);
}

void CodeCreator::visitRet(Ret *ret) {
    /* Code For Ret Goes Here */
    wasRet = true;
    TType type = env->getRetType(curFunc);

    if (type.isBool()) {
        lt = env->getNextLabel();
        lf = env->getNextLabel();
        ln = env->getNextLabel();
    }
    string tmp_lt = lt, tmp_lf = lf, tmp_ln = ln;

    ret->expr_->accept(this);

    if (type.isBool()) {
        genStdTrueFalse(tmp_lt, tmp_lf, tmp_ln);
    }

    i = new Pop(Addr(Reg::EAX).toStr());
    emit(i);

    emitRetSequence();
}

void CodeCreator::visitVRet(VRet *vret) {
    /* Code For VRet Goes Here */
    wasRet = true;
    emitRetSequence();
}

void CodeCreator::visitCond(Cond *cond) {
    /* Code For Cond Goes Here */
    lt = env->getNextLabel();
    ln = env->getNextLabel();
    lf = ln;
    string tmp_lt = lt;
    string tmp_ln = ln;
    string tmp_lf = lf;

    cond->expr_->accept(this);

    i = new Label(tmp_lt);
    emit(i);
    cond->stmt_->accept(this);
    i = new Label(tmp_ln);
    emit(i);
}

void CodeCreator::visitCondElse(CondElse *condelse) {
    /* Code For CondElse Goes Here */
    lt = env->getNextLabel();
    lf = env->getNextLabel();
    ln = env->getNextLabel();
    string tmp_lt = lt;
    string tmp_ln = ln;
    string tmp_lf = lf;

    condelse->expr_->accept(this);
    i = new Label(tmp_lt);
    emit(i);
    condelse->stmt_1->accept(this);
    i = new Jmp(tmp_ln);
    emit(i);
    i = new Label(tmp_lf);
    emit(i);
    condelse->stmt_2->accept(this);
    i = new Label(tmp_ln);
    emit(i);
}

void CodeCreator::visitWhile(While *w) {
    /* Code For While Goes Here */
    string lbeg = env->getNextLabel();
    lt = env->getNextLabel();
    lf = env->getNextLabel();
    ln = lf;
    string tmp_lt = lt;
    string tmp_ln = ln;
    string tmp_lf = lf;

    i = new Label(lbeg, "  #loop condition");
    emit(i);
    w->expr_->accept(this);
    i = new Label(lt, "  #loop body");
    emit(i);

    w->stmt_->accept(this);
    i = new Jmp(lbeg);
    emit(i);

    i = new Label(tmp_ln, "  # End while");
    emit(i);
}

void CodeCreator::visitFor(For *f) {
    /* Code For For Goes Here */

    f->type_->accept(this);
    visitIdent(f->ident_1);
    visitIdent(f->ident_2);
    f->stmt_->accept(this);
}

void CodeCreator::visitSExp(SExp *sexp) {
    /* Code For SExp Goes Here */
    // lt = env->getNextLabel();
    // lf = env->getNextLabel();
    // ln = env->getNextLabel();
    sexp->expr_->accept(this);
    // a bit useless, isn't it?
}

void CodeCreator::emitLocalVar(string ident) {
    env->addVarToCurScope(ident, declType, nrLoc);
    nrLoc--;
}

void CodeCreator::visitNoInit(NoInit *noinit) {
    /* Code For NoInit Goes Here */

    emitLocalVar(noinit->ident_);
    visitIdent(noinit->ident_);

    int pos = env->getPos(noinit->ident_);
    string arg = "$0";
    if (declType.isString()) {
        arg = "$" + env->getLabStr("");
    }

    i = new Mov(arg, Addr(Reg::EBP, pos).toStr());
    emit(i);
}

void CodeCreator::visitInit(Init *init) {
    /* Code For Init Goes Here */

    visitIdent(init->ident_);

    if (declType.isBool()) {
        lt = env->getNextLabel();
        lf = env->getNextLabel();
        ln = env->getNextLabel();
    }
    string tmp_lt = lt, tmp_lf = lf, tmp_ln = ln;

    init->expr_->accept(this);
    // Expr can't change type of declType -> it would be detected in frontend

    if (declType.isBool()) {
        genStdTrueFalse(tmp_lt, tmp_lf, tmp_ln);
    }

    emitLocalVar(init->ident_);  // Todo: Check if fixed

    i = new Pop(Addr(Reg::EAX).toStr());
    emit(i);
    int pos = env->getPos(init->ident_);
    i = new Mov(Addr(Reg::EAX).toStr(), Addr(Reg::EBP, pos).toStr());
    emit(i);
}

void CodeCreator::visitInt(Int *i) {
    /* Code For Int Goes Here */
    declType = TType(vType::tInt);
    lastType = declType;
}

void CodeCreator::visitStr(Str *str) {
    /* Code For Str Goes Here */
    declType = TType(vType::tStr);
    lastType = declType;
}

void CodeCreator::visitBool(Bool *b) {
    /* Code For Bool Goes Here */
    declType = TType(vType::tBool);
    lastType = declType;
}

void CodeCreator::visitVoid(Void *v) {
    /* Code For Void Goes Here */
    declType = TType(vType::tVoid);
    lastType = declType;
}

void CodeCreator::visitFun(Fun *fun) {
    /* Code For Fun Goes Here */

    fun->type_->accept(this);
    fun->listtype_->accept(this);
}

void CodeCreator::visitBType(BType *btype) {
    /* Code For BType Goes Here */

    btype->basictype_->accept(this);
}

void CodeCreator::visitClsType(ClsType *clstype) {
    /* Code For ClsType Goes Here */

    visitIdent(clstype->ident_);
}

void CodeCreator::visitArrayType(ArrayType *arraytype) {
    /* Code For ArrayType Goes Here */

    arraytype->typename_->accept(this);
}

void CodeCreator::visitNormalType(NormalType *normaltype) {
    /* Code For NormalType Goes Here */

    normaltype->typename_->accept(this);
}

void CodeCreator::visitLvVar(LvVar *lvvar) {
    /* Code For LvVar Goes Here */
    lastType = env->lookupVarType(lvvar->ident_);
    // varIdent = lvvar->ident_;
    if (!genCode)
        return;

    int pos = env->getPos(lvvar->ident_) * MULTIPLIER;

    stringstream ss;
    ss << pos << "(, \%ebp, 1)";

    i = new Lea(ss.str(), Addr(Reg::EAX).toStr());
    emit(i);
    visitIdent(lvvar->ident_);
}

void CodeCreator::visitLvTab(LvTab *lvtab) {
    /* Code For LvTab Goes Here */

    lvtab->expr_1->accept(this);
    lvtab->expr_2->accept(this);
}

void CodeCreator::visitLvAttr(LvAttr *lvattr) {
    /* Code For LvAttr Goes Here */

    lvattr->expr_->accept(this);
    visitIdent(lvattr->ident_);
}

void CodeCreator::visitEAttr(EAttr *eattr) {
    /* Code For EAttr Goes Here */

    eattr->expr_->accept(this);
    visitIdent(eattr->ident_);
}

void CodeCreator::visitEMetCall(EMetCall *emetcall) {
    /* Code For EMetCall Goes Here */

    emetcall->expr_->accept(this);
    visitIdent(emetcall->ident_);
    emetcall->listexpr_->accept(this);
}

void CodeCreator::visitECastNull(ECastNull *ecastnull) {
    /* Code For ECastNull Goes Here */

    visitIdent(ecastnull->ident_);
}

void CodeCreator::visitEAt(EAt *eat) {
    /* Code For EAt Goes Here */

    eat->expr_1->accept(this);
    eat->expr_2->accept(this);
}

void CodeCreator::visitENewArr(ENewArr *enewarr) {
    /* Code For ENewArr Goes Here */

    enewarr->basictype_->accept(this);
    enewarr->expr_->accept(this);
}

void CodeCreator::visitENewClArr(ENewClArr *enewclarr) {
    /* Code For ENewClArr Goes Here */

    visitIdent(enewclarr->ident_);
    enewclarr->expr_->accept(this);
}

void CodeCreator::visitENewCls(ENewCls *enewcls) {
    /* Code For ENewCls Goes Here */

    visitIdent(enewcls->ident_);
}

void CodeCreator::visitEVar(EVar *evar) {
    /* Code For EVar Goes Here */
    TType varT = env->lookupVarType(evar->ident_);
    int pos = env->getPos(evar->ident_);

    if (varT.isBool()) {
        i = new Mov(Addr(Reg::EBP, pos).toStr(), Addr(Reg::EAX).toStr());
        emit(i);
        i = new Testz(Addr(Reg::EAX).toStr(), Addr(Reg::EAX).toStr());
        emit(i);
        // JZ
        // i = new Jz(lf);
        // emit(i);
        // i = new Jmp(lt);
        // emit(i);

        // TODO: Upgrade?
        if (lf == ln) {       // or
            i = new Jnz(lt);  // != 0 ->was lf
            emit(i);
        } else if (lt == ln) {  // and
            i = new Jz(lf);     // == 0
            emit(i);
        } else {
            i = new Jz(lf);
            emit(i);
            i = new Jmp(lt);
            emit(i);
        }

        return;
    }

    i = new Push(Addr(Reg::EBP, pos).toStr());
    emit(i);
    visitIdent(evar->ident_);
    lastType = varT;
}

void CodeCreator::visitELitInt(ELitInt *elitint) {
    /* Code For ELitInt Goes Here */
    stringstream ss;

    ss << "$" << elitint->integer_;
    i = new Push(ss.str());
    emit(i);

    visitInteger(elitint->integer_);

    lastType = TType(vType::tInt);
}

void CodeCreator::visitELitTrue(ELitTrue *elittrue) {
    /* Code For ELitTrue Goes Here */
    // i = new Push("$1");
    // emit(i);
    if (lt != ln) {
        i = new Jmp(lt);
        emit(i);
    }
    lastType = TType(vType::tBool);
}

void CodeCreator::visitELitFalse(ELitFalse *elitfalse) {
    /* Code For ELitFalse Goes Here */
    if (lf != ln) {
        i = new Jmp(lf);
        emit(i);
    }
    lastType = TType(vType::tBool);
}

void CodeCreator::visitEApp(EApp *eapp) {
    /* Code For EApp Goes Here */

    eapp->listexpr_->accept(this);
    visitIdent(eapp->ident_);

    i = new Call(eapp->ident_);
    emit(i);

    // Zdejmujemy argumenty
    stringstream ss;
    ss << "$" << (MULTIPLIER * (eapp->listexpr_->size()));
    i = new Add(ss.str(), Addr(Reg::ESP).toStr());
    emit(i);

    lastType = env->getRetType(eapp->ident_);
    if (lastType.isBool()) {
        i = new Testz(Addr(Reg::EAX).toStr(), Addr(Reg::EAX).toStr());
        emit(i);
        // JZ
        i = new Jz(lf);
        emit(i);
        i = new Jmp(lt);
        emit(i);
        return;
    }

    // Wrzucamy wynik
    if (!(env->getRetType(eapp->ident_).isVoid())) {
        i = new Push(Addr(Reg::EAX).toStr());
        emit(i);
    }
}

void CodeCreator::visitEString(EString *estring) {
    /* Code For EString Goes Here */

    visitString(estring->string_);
    string lab = "$" + env->getLabStr(estring->string_);
    i = new Push(lab);
    emit(i);
    lastType = TType(vType::tStr);
}

void CodeCreator::visitNeg(Neg *neg) {
    /* Code For Neg Goes Here */

    neg->expr_->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());
    emit(i);
    i = new NegI(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(Addr(Reg::ECX).toStr());
    emit(i);
}

void CodeCreator::visitNot(Not *n) {
    /* Code For Not Goes Here */
    string tmp_lt = lt;
    string tmp_lf = lf;
    string tmp_ln = ln;

    lt = tmp_lf;  // We swap the labels inside the expression
    lf = tmp_lt;

    n->expr_->accept(this);

    lt = tmp_lt;
    lf = tmp_lf;
}

void CodeCreator::visitEMul(EMul *emul) {
    /* Code For EMul Goes Here */

    emul->expr_1->accept(this);
    emul->expr_2->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Pop(Addr(Reg::EAX).toStr());  // First res
    emit(i);
    emul->mulop_->accept(this);
}

void CodeCreator::visitEAdd(EAdd *eadd) {
    /* Code For EAdd Goes Here */

    eadd->expr_1->accept(this);
    eadd->expr_2->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Pop(Addr(Reg::EAX).toStr());  // First res
    emit(i);

    eadd->addop_->accept(this);
}

Instruction *CodeCreator::genCorrectJmp(string lt) {
    Instruction *res;

    switch (lastRelop.getOp()) {
        case vRelop::oLt:
            res = new Jlt(lt);
            break;
        case vRelop::oLe:
            res = new Jle(lt);
            break;
        case vRelop::oGt:
            res = new Jgt(lt);
            break;
        case vRelop::oGe:
            res = new Jge(lt);
            break;
        case vRelop::oEq:
            res = new Jeq(lt);
            break;
        case vRelop::oNeq:
            res = new Jneq(lt);
            break;
    }

    return res;
}

void CodeCreator::visitERel(ERel *erel) {
    /* Code For ERel Goes Here */
    string tmp_lt = lt;
    string tmp_lf = lf;
    string tmp_ln = ln;

    erel->expr_1->accept(this);

    lt = tmp_lt;
    lf = tmp_lf;
    ln = tmp_ln;
    erel->expr_2->accept(this);

    lt = tmp_lt;
    lf = tmp_lf;
    ln = tmp_ln;

    i = new Pop(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Pop(Addr(Reg::EAX).toStr());  // First res
    emit(i);

    erel->relop_->accept(this);

    i = new Cmp(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);

    i = genCorrectJmp(lt);
    emit(i);

    i = new Jmp(lf);
    emit(i);

    lastType = TType(vType::tBool);
}

void CodeCreator::visitEAnd(EAnd *eand) {
    /* Code For EAnd Goes Here */

    string tmp_lt = lt;
    string tmp_lf = lf;
    string tmp_ln = ln;

    string lmid = env->getNextLabel();

    lt = lmid;
    ln = lmid;
    eand->expr_1->accept(this);
    i = new Label(lmid, "  # mid");
    emit(i);
    lt = tmp_lt;
    ln = tmp_ln;
    eand->expr_2->accept(this);
    lastType = TType(vType::tBool);
}

void CodeCreator::visitEOr(EOr *eor) {
    /* Code For EOr Goes Here */
    string tmp_lt = lt;
    string tmp_lf = lf;
    string tmp_ln = ln;

    string lmid = env->getNextLabel();

    lf = lmid;
    ln = lmid;

    eor->expr_1->accept(this);

    i = new Label(lmid);
    emit(i);

    lf = tmp_lf;
    ln = tmp_ln;

    eor->expr_2->accept(this);
    lastType = TType(vType::tBool);
}

void CodeCreator::concatStrings() {
    i = new Push(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());  // First res
    emit(i);

    i = new Call("__concatStrings");
    emit(i);
    i = new Add("$8", Addr(Reg::ESP).toStr());  // forget args
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitPlus(Plus *plus) {
    /* Code For Plus Goes Here */

    if (lastType.isString()) {
        concatStrings();
        return;
    }

    i = new Add(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitMinus(Minus *minus) {
    /* Code For Minus Goes Here */
    i = new Sub(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitTimes(Times *times) {
    /* Code For Times Goes Here */
    i = new IMul(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitDiv(Div *div) {
    /* Code For Div Goes Here */
    i = new Cdq();
    emit(i);
    i = new IDiv(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitMod(Mod *mod) {
    /* Code For Mod Goes Here */
    i = new Cdq();
    emit(i);
    i = new IDiv(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(rtoStr(Reg::EDX));
    emit(i);
}

void CodeCreator::visitLTH(LTH *lth) {
    /* Code For LTH Goes Here */
    lastRelop = TRelop(vRelop::oLt);
}

void CodeCreator::visitLE(LE *le) {
    /* Code For LE Goes Here */
    lastRelop = TRelop(vRelop::oLe);
}

void CodeCreator::visitGTH(GTH *gth) {
    /* Code For GTH Goes Here */
    lastRelop = TRelop(vRelop::oGt);
}

void CodeCreator::visitGE(GE *ge) {
    /* Code For GE Goes Here */
    lastRelop = TRelop(vRelop::oGe);
}

void CodeCreator::visitEQU(EQU *equ) {
    /* Code For EQU Goes Here */
    lastRelop = TRelop(vRelop::oEq);
}

void CodeCreator::visitNE(NE *ne) {
    /* Code For NE Goes Here */
    lastRelop = TRelop(vRelop::oNeq);
}

void CodeCreator::visitListTopDef(ListTopDef *listtopdef) {
    for (ListTopDef::iterator i = listtopdef->begin(); i != listtopdef->end();
         ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListArg(ListArg *listarg) {
    for (ListArg::iterator i = listarg->begin(); i != listarg->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListClsElems(ListClsElems *listclselems) {
    for (ListClsElems::iterator i = listclselems->begin();
         i != listclselems->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListStmt(ListStmt *liststmt) {
    for (ListStmt::iterator i = liststmt->begin(); i != liststmt->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListItem(ListItem *listitem) {
    for (ListItem::iterator i = listitem->begin(); i != listitem->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListType(ListType *listtype) {
    for (ListType::iterator i = listtype->begin(); i != listtype->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListExpr(ListExpr *listexpr) {
    for (ListExpr::reverse_iterator i = listexpr->rbegin();
         i != listexpr->rend(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitInteger(Integer x) {
    /* Code for Integer Goes Here */
}

void CodeCreator::visitChar(Char x) {
    /* Code for Char Goes Here */
}

void CodeCreator::visitDouble(Double x) {
    /* Code for Double Goes Here */
}

void CodeCreator::visitString(String x) {
    /* Code for String Goes Here */
}

void CodeCreator::visitIdent(Ident x) {
    /* Code for Ident Goes Here */
}
