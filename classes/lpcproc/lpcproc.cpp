// dLabPro class CLPCproc (LPCproc)
// - Linear prediction coding (LPC) analysis and synthesis
//
// AUTHOR : Guntram Strecha
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify lpcproc.def instead.
// 
// Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
// - Chair of System Theory and Speech Technology, TU Dresden
// - Chair of Communications Engineering, BTU Cottbus
// 
// This file is part of dLabPro.
// 
// dLabPro is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
// 
// dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with dLabPro. If not, see <http://www.gnu.org/licenses/>.


//{{CGEN_INCLUDE
//}}CGEN_END
#include "dlp_lpcproc.h"

// Class CLPCproc

CLPCproc::CLPCproc(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	DEBUGMSG(-1,"CLPCproc::CLPCproc; (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	dlp_strcpy(m_lpClassName,"LPCproc");
	dlp_strcpy(m_lpObsoleteName,"");
	dlp_strcpy(m_lpProjectName,"LPCproc");
	dlp_strcpy(m_version.no,"1.0 DLP");
	dlp_strcpy(m_version.date,"");
	m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(AutoRegisterWords()));
		Init(TRUE);
	}
}

CLPCproc::~CLPCproc()
{
  //{{CGEN_DONECODE
  if(m_lpMemLpc != NULL) dlp_free(m_lpMemLpc);
  DONE;
  //}}CGEN_DONECODE
}

INT16 CLPCproc::AutoRegisterWords()
{
	DEBUGMSG(-1,"CLPCproc::AutoRegisterWords",0,0,0);
	IF_NOK(inherited::AutoRegisterWords()) return NOT_EXEC;

	//{{CGEN_REGISTERWORDS
	REGISTER_METHOD("-analyze","",LPMF(CLPCproc,OnAnalyze),"Run LPC analysis.",0,"<data idSignal> <data idPitch> <data idReal> <data idImag> <LPCproc this>","")
	REGISTER_METHOD("-status","",LPMF(CLPCproc,Status),"Display status information.",0,"<LPCproc this>","")
	REGISTER_FIELD("coeff","",LPMV(m_nCoeff),NULL,"Number of LPC coefficients.",0,2002,1,"short",(INT16)50)
	REGISTER_FIELD("mem_lpc","",LPMV(m_lpMemLpc),NULL,"synthesis filter states",FF_HIDDEN | FF_NOSAVE,6000,1,"double*",NULL)
	//}}CGEN_REGISTERWORDS

	return O_K;
}

INT16 CLPCproc::Init(BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CLPCproc::Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	//{{CGEN_INITCODE
  INIT;
	//}}CGEN_INITCODE

	// If last derivation call reset (do not reset members; already done by Init())
	if (bCallVirtual) return Reset(FALSE);
	else              return O_K;
}

INT16 CLPCproc::Reset(BOOL bResetMembers)
{
	DEBUGMSG(-1,"CLPCproc::Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	//{{CGEN_RESETCODE
  return RESET;
	//}}CGEN_RESETCODE

	return O_K;
}

INT16 CLPCproc::ClassProc()
{
	//{{CGEN_CLASSCODE
  return CLASSPROC;
	//}}CGEN_CLASSCODE

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CLPCproc::Serialize(CDN3Stream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CLPCproc::SerializeXml(CXmlStream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CLPCproc::Deserialize(CDN3Stream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CLPCproc::DeserializeXml(CXmlStream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CLPCproc::Copy(CDlpObject* __iSrc)
{
	//{{CGEN_COPYCODE
  return COPY;
	//}}CGEN_COPYCODE

	return O_K;
}

// Runtime class type information and class factory
INT16 CLPCproc::InstallProc(void* lpItp)
{
	//{{CGEN_INSTALLCODE
  return INSTALL;
	//}}CGEN_INSTALLCODE

	return O_K;
}

CLPCproc* CLPCproc::CreateInstance(const char* lpName)
{
	CLPCproc* lpNewInstance;
	ICREATEEX(CLPCproc,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CLPCproc::GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;
	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CLPCproc::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CLPCproc::InstallProc;
	lpClassWord->ex.fct.lpProject   = "LPCproc";
	lpClassWord->ex.fct.lpBaseClass = "FBAproc";
	lpClassWord->lpComment          = "Linear prediction coding (LPC) analysis and synthesis";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CLPCproc";
	lpClassWord->ex.fct.lpAuthor    = "Guntram Strecha";

	dlp_strcpy(lpClassWord->lpName             ,"LPCproc");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"1.0 DLP");

	return O_K;
}

INT16 CLPCproc::GetInstanceInfo(SWord* lpClassWord)
{
	return CLPCproc::GetClassInfo(lpClassWord);
}

BOOL CLPCproc::IsKindOf(const char* lpClassName)
{
  if (dlp_strncmp(lpClassName,"LPCproc",L_NAMES) == 0) return TRUE;
  else return inherited::IsKindOf(lpClassName);
}

INT16 CLPCproc::ResetAllOptions(BOOL bInit)
{
	DEBUGMSG(-1,"CLPCproc::ResetAllOptions;",0,0,0);
	//{{CGEN_RESETALLOPTIONS
	//}}CGEN_RESETALLOPTIONS

	return inherited::ResetAllOptions(bInit);
}

// Generated primary method invocation functions

#ifndef __NOITP
//{{CGEN_PMIC
INT16 CLPCproc::OnAnalyze()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* idImag = MIC_GET_I_EX(idImag,data,1,1);
	data* idReal = MIC_GET_I_EX(idReal,data,2,2);
	data* idPitch = MIC_GET_I_EX(idPitch,data,3,3);
	data* idSignal = MIC_GET_I_EX(idSignal,data,4,4);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Analyze(idSignal, idPitch, idReal, idImag);
	return __nErr;
}

//}}CGEN_PMIC
#endif /* #ifndef __NOITP */


// Generated secondary method invocation functions

//{{CGEN_SMIC
//}}CGEN_SMIC


// Generated option change callback functions

//{{CGEN_OCCF
//}}CGEN_OCCF


// Generated field change callback functions

//{{CGEN_FCCF
//}}CGEN_FCCF


// EOF
