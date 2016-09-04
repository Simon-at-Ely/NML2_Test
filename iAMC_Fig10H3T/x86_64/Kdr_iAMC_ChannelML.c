/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gmax _p[0]
#define conductance _p[1]
#define m_instances _p[2]
#define m_steadyState_TIME_SCALE _p[3]
#define m_steadyState_VOLT_SCALE _p[4]
#define m_timeCourse_TIME_SCALE _p[5]
#define m_timeCourse_VOLT_SCALE _p[6]
#define n_instances _p[7]
#define n_steadyState_TIME_SCALE _p[8]
#define n_steadyState_VOLT_SCALE _p[9]
#define n_timeCourse_TIME_SCALE _p[10]
#define n_timeCourse_VOLT_SCALE _p[11]
#define gion _p[12]
#define m_steadyState_V _p[13]
#define m_steadyState_x _p[14]
#define m_timeCourse_V _p[15]
#define m_timeCourse_t _p[16]
#define m_rateScale _p[17]
#define m_fcond _p[18]
#define m_inf _p[19]
#define m_tauUnscaled _p[20]
#define m_tau _p[21]
#define n_steadyState_V _p[22]
#define n_steadyState_x _p[23]
#define n_timeCourse_V _p[24]
#define n_timeCourse_t _p[25]
#define n_rateScale _p[26]
#define n_fcond _p[27]
#define n_inf _p[28]
#define n_tauUnscaled _p[29]
#define n_tau _p[30]
#define conductanceScale _p[31]
#define fopen0 _p[32]
#define fopen _p[33]
#define g _p[34]
#define m_q _p[35]
#define n_q _p[36]
#define temperature _p[37]
#define ek _p[38]
#define ik _p[39]
#define rate_m_q _p[40]
#define rate_n_q _p[41]
#define Dm_q _p[42]
#define Dn_q _p[43]
#define v _p[44]
#define _g _p[45]
#define _ion_ik	*_ppvar[0]._pval
#define _ion_dikdv	*_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Kdr_iAMC_ChannelML", _hoc_setdata,
 "rates_Kdr_iAMC_ChannelML", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_Kdr_iAMC_ChannelML", "S/cm2",
 "conductance_Kdr_iAMC_ChannelML", "uS",
 "m_steadyState_TIME_SCALE_Kdr_iAMC_ChannelML", "ms",
 "m_steadyState_VOLT_SCALE_Kdr_iAMC_ChannelML", "mV",
 "m_timeCourse_TIME_SCALE_Kdr_iAMC_ChannelML", "ms",
 "m_timeCourse_VOLT_SCALE_Kdr_iAMC_ChannelML", "mV",
 "n_steadyState_TIME_SCALE_Kdr_iAMC_ChannelML", "ms",
 "n_steadyState_VOLT_SCALE_Kdr_iAMC_ChannelML", "mV",
 "n_timeCourse_TIME_SCALE_Kdr_iAMC_ChannelML", "ms",
 "n_timeCourse_VOLT_SCALE_Kdr_iAMC_ChannelML", "mV",
 "gion_Kdr_iAMC_ChannelML", "S/cm2",
 "m_timeCourse_t_Kdr_iAMC_ChannelML", "ms",
 "m_tauUnscaled_Kdr_iAMC_ChannelML", "ms",
 "m_tau_Kdr_iAMC_ChannelML", "ms",
 "n_timeCourse_t_Kdr_iAMC_ChannelML", "ms",
 "n_tauUnscaled_Kdr_iAMC_ChannelML", "ms",
 "n_tau_Kdr_iAMC_ChannelML", "ms",
 "g_Kdr_iAMC_ChannelML", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double m_q0 = 0;
 static double n_q0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"Kdr_iAMC_ChannelML",
 "gmax_Kdr_iAMC_ChannelML",
 "conductance_Kdr_iAMC_ChannelML",
 "m_instances_Kdr_iAMC_ChannelML",
 "m_steadyState_TIME_SCALE_Kdr_iAMC_ChannelML",
 "m_steadyState_VOLT_SCALE_Kdr_iAMC_ChannelML",
 "m_timeCourse_TIME_SCALE_Kdr_iAMC_ChannelML",
 "m_timeCourse_VOLT_SCALE_Kdr_iAMC_ChannelML",
 "n_instances_Kdr_iAMC_ChannelML",
 "n_steadyState_TIME_SCALE_Kdr_iAMC_ChannelML",
 "n_steadyState_VOLT_SCALE_Kdr_iAMC_ChannelML",
 "n_timeCourse_TIME_SCALE_Kdr_iAMC_ChannelML",
 "n_timeCourse_VOLT_SCALE_Kdr_iAMC_ChannelML",
 0,
 "gion_Kdr_iAMC_ChannelML",
 "m_steadyState_V_Kdr_iAMC_ChannelML",
 "m_steadyState_x_Kdr_iAMC_ChannelML",
 "m_timeCourse_V_Kdr_iAMC_ChannelML",
 "m_timeCourse_t_Kdr_iAMC_ChannelML",
 "m_rateScale_Kdr_iAMC_ChannelML",
 "m_fcond_Kdr_iAMC_ChannelML",
 "m_inf_Kdr_iAMC_ChannelML",
 "m_tauUnscaled_Kdr_iAMC_ChannelML",
 "m_tau_Kdr_iAMC_ChannelML",
 "n_steadyState_V_Kdr_iAMC_ChannelML",
 "n_steadyState_x_Kdr_iAMC_ChannelML",
 "n_timeCourse_V_Kdr_iAMC_ChannelML",
 "n_timeCourse_t_Kdr_iAMC_ChannelML",
 "n_rateScale_Kdr_iAMC_ChannelML",
 "n_fcond_Kdr_iAMC_ChannelML",
 "n_inf_Kdr_iAMC_ChannelML",
 "n_tauUnscaled_Kdr_iAMC_ChannelML",
 "n_tau_Kdr_iAMC_ChannelML",
 "conductanceScale_Kdr_iAMC_ChannelML",
 "fopen0_Kdr_iAMC_ChannelML",
 "fopen_Kdr_iAMC_ChannelML",
 "g_Kdr_iAMC_ChannelML",
 0,
 "m_q_Kdr_iAMC_ChannelML",
 "n_q_Kdr_iAMC_ChannelML",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 46, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	m_instances = 1;
 	m_steadyState_TIME_SCALE = 1;
 	m_steadyState_VOLT_SCALE = 1;
 	m_timeCourse_TIME_SCALE = 1;
 	m_timeCourse_VOLT_SCALE = 1;
 	n_instances = 1;
 	n_steadyState_TIME_SCALE = 1;
 	n_steadyState_VOLT_SCALE = 1;
 	n_timeCourse_TIME_SCALE = 1;
 	n_timeCourse_VOLT_SCALE = 1;
 	_prop->param = _p;
 	_prop->param_size = 46;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Kdr_iAMC_ChannelML_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", 1.0);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 46, 3);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kdr_iAMC_ChannelML /home/Simon/NML2_Test/AOB_mitral_cell2/x86_64/Kdr_iAMC_ChannelML.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=Kdr_iAMC_ChannelML type=ionChannelHH)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   Dm_q = rate_m_q ;
   Dn_q = rate_n_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Dm_q = Dm_q  / (1. - dt*( 0.0 )) ;
 Dn_q = Dn_q  / (1. - dt*( 0.0 )) ;
 return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    m_q = m_q - dt*(- ( rate_m_q ) ) ;
    n_q = n_q - dt*(- ( rate_n_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   m_steadyState_V = v / m_steadyState_VOLT_SCALE ;
   if ( m_steadyState_V < ( - 66.67 ) ) {
     m_steadyState_x = 0.0 ;
     }
   else {
     m_steadyState_x = 0.005 * m_steadyState_V + 0.35 ;
     }
   m_timeCourse_V = v / m_timeCourse_VOLT_SCALE ;
   if ( m_timeCourse_V < ( - 66.67 ) ) {
     m_timeCourse_t = 230.2566 * m_timeCourse_TIME_SCALE ;
     }
   else {
     m_timeCourse_t = ( 29.156 * exp ( - ( m_timeCourse_V + 55.0 ) / 5.8842 ) + 18.394 ) * m_timeCourse_TIME_SCALE ;
     }
   m_rateScale = 1.0 ;
   m_fcond = pow( m_q , m_instances ) ;
   m_inf = m_steadyState_x ;
   m_tauUnscaled = m_timeCourse_t ;
   m_tau = m_tauUnscaled / m_rateScale ;
   n_steadyState_V = v / n_steadyState_VOLT_SCALE ;
   if ( n_steadyState_V < ( 5.0 ) ) {
     n_steadyState_x = 0.0 ;
     }
   else {
     n_steadyState_x = ( ( - 0.006 * n_steadyState_V ) + 0.40 ) ;
     }
   n_timeCourse_V = v / n_timeCourse_VOLT_SCALE ;
   n_timeCourse_t = 1.5 * n_timeCourse_TIME_SCALE ;
   n_rateScale = 1.0 ;
   n_fcond = pow( n_q , n_instances ) ;
   n_inf = n_steadyState_x ;
   n_tauUnscaled = n_timeCourse_t ;
   n_tau = n_tauUnscaled / n_rateScale ;
   rate_m_q = ( m_inf - m_q ) / m_tau ;
   rate_n_q = ( n_inf - n_q ) / n_tau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  m_q = m_q0;
  n_q = n_q0;
 {
   ek = - 86.5 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   m_q = m_inf ;
   n_q = n_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
 }}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = m_fcond * n_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ik = gion * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
 { {
 for (; t < _break; t += dt) {
   states(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m_q) - _p;  _dlist1[0] = &(Dm_q) - _p;
 _slist1[1] = &(n_q) - _p;  _dlist1[1] = &(Dn_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
