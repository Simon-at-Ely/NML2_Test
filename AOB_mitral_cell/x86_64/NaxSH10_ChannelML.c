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
#define m_forwardRate_rate _p[3]
#define m_forwardRate_midpoint _p[4]
#define m_forwardRate_scale _p[5]
#define m_reverseRate_rate _p[6]
#define m_reverseRate_midpoint _p[7]
#define m_reverseRate_scale _p[8]
#define m_timeCourse_TIME_SCALE _p[9]
#define m_timeCourse_VOLT_SCALE _p[10]
#define m_q10Settings_q10Factor _p[11]
#define m_q10Settings_experimentalTemp _p[12]
#define m_q10Settings_TENDEGREES _p[13]
#define h_instances _p[14]
#define h_steadyState_rate _p[15]
#define h_steadyState_midpoint _p[16]
#define h_steadyState_scale _p[17]
#define h_forwardRate_rate _p[18]
#define h_forwardRate_midpoint _p[19]
#define h_forwardRate_scale _p[20]
#define h_reverseRate_rate _p[21]
#define h_reverseRate_midpoint _p[22]
#define h_reverseRate_scale _p[23]
#define h_timeCourse_TIME_SCALE _p[24]
#define h_timeCourse_VOLT_SCALE _p[25]
#define h_q10Settings_q10Factor _p[26]
#define h_q10Settings_experimentalTemp _p[27]
#define h_q10Settings_TENDEGREES _p[28]
#define gion _p[29]
#define m_forwardRate_x _p[30]
#define m_forwardRate_r _p[31]
#define m_reverseRate_x _p[32]
#define m_reverseRate_r _p[33]
#define m_timeCourse_V _p[34]
#define m_timeCourse_ALPHA _p[35]
#define m_timeCourse_BETA _p[36]
#define m_timeCourse_t _p[37]
#define m_q10Settings_q10 _p[38]
#define m_rateScale _p[39]
#define m_alpha _p[40]
#define m_beta _p[41]
#define m_fcond _p[42]
#define m_inf _p[43]
#define m_tauUnscaled _p[44]
#define m_tau _p[45]
#define h_steadyState_x _p[46]
#define h_forwardRate_x _p[47]
#define h_forwardRate_r _p[48]
#define h_reverseRate_x _p[49]
#define h_reverseRate_r _p[50]
#define h_timeCourse_V _p[51]
#define h_timeCourse_ALPHA _p[52]
#define h_timeCourse_BETA _p[53]
#define h_timeCourse_t _p[54]
#define h_q10Settings_q10 _p[55]
#define h_rateScale _p[56]
#define h_alpha _p[57]
#define h_beta _p[58]
#define h_inf _p[59]
#define h_tauUnscaled _p[60]
#define h_tau _p[61]
#define h_fcond _p[62]
#define conductanceScale _p[63]
#define fopen0 _p[64]
#define fopen _p[65]
#define g _p[66]
#define m_q _p[67]
#define h_q _p[68]
#define temperature _p[69]
#define ena _p[70]
#define ina _p[71]
#define rate_m_q _p[72]
#define rate_h_q _p[73]
#define Dm_q _p[74]
#define Dh_q _p[75]
#define v _p[76]
#define _g _p[77]
#define _ion_ina	*_ppvar[0]._pval
#define _ion_dinadv	*_ppvar[1]._pval
 
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
 "setdata_NaxSH10_ChannelML", _hoc_setdata,
 "rates_NaxSH10_ChannelML", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_NaxSH10_ChannelML", "S/cm2",
 "conductance_NaxSH10_ChannelML", "uS",
 "m_forwardRate_rate_NaxSH10_ChannelML", "kHz",
 "m_forwardRate_midpoint_NaxSH10_ChannelML", "mV",
 "m_forwardRate_scale_NaxSH10_ChannelML", "mV",
 "m_reverseRate_rate_NaxSH10_ChannelML", "kHz",
 "m_reverseRate_midpoint_NaxSH10_ChannelML", "mV",
 "m_reverseRate_scale_NaxSH10_ChannelML", "mV",
 "m_timeCourse_TIME_SCALE_NaxSH10_ChannelML", "ms",
 "m_timeCourse_VOLT_SCALE_NaxSH10_ChannelML", "mV",
 "m_q10Settings_experimentalTemp_NaxSH10_ChannelML", "K",
 "m_q10Settings_TENDEGREES_NaxSH10_ChannelML", "K",
 "h_steadyState_midpoint_NaxSH10_ChannelML", "mV",
 "h_steadyState_scale_NaxSH10_ChannelML", "mV",
 "h_forwardRate_rate_NaxSH10_ChannelML", "kHz",
 "h_forwardRate_midpoint_NaxSH10_ChannelML", "mV",
 "h_forwardRate_scale_NaxSH10_ChannelML", "mV",
 "h_reverseRate_rate_NaxSH10_ChannelML", "kHz",
 "h_reverseRate_midpoint_NaxSH10_ChannelML", "mV",
 "h_reverseRate_scale_NaxSH10_ChannelML", "mV",
 "h_timeCourse_TIME_SCALE_NaxSH10_ChannelML", "ms",
 "h_timeCourse_VOLT_SCALE_NaxSH10_ChannelML", "mV",
 "h_q10Settings_experimentalTemp_NaxSH10_ChannelML", "K",
 "h_q10Settings_TENDEGREES_NaxSH10_ChannelML", "K",
 "gion_NaxSH10_ChannelML", "S/cm2",
 "m_forwardRate_r_NaxSH10_ChannelML", "kHz",
 "m_reverseRate_r_NaxSH10_ChannelML", "kHz",
 "m_timeCourse_t_NaxSH10_ChannelML", "ms",
 "m_alpha_NaxSH10_ChannelML", "kHz",
 "m_beta_NaxSH10_ChannelML", "kHz",
 "m_tauUnscaled_NaxSH10_ChannelML", "ms",
 "m_tau_NaxSH10_ChannelML", "ms",
 "h_forwardRate_r_NaxSH10_ChannelML", "kHz",
 "h_reverseRate_r_NaxSH10_ChannelML", "kHz",
 "h_timeCourse_t_NaxSH10_ChannelML", "ms",
 "h_alpha_NaxSH10_ChannelML", "kHz",
 "h_beta_NaxSH10_ChannelML", "kHz",
 "h_tauUnscaled_NaxSH10_ChannelML", "ms",
 "h_tau_NaxSH10_ChannelML", "ms",
 "g_NaxSH10_ChannelML", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double h_q0 = 0;
 static double m_q0 = 0;
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
"NaxSH10_ChannelML",
 "gmax_NaxSH10_ChannelML",
 "conductance_NaxSH10_ChannelML",
 "m_instances_NaxSH10_ChannelML",
 "m_forwardRate_rate_NaxSH10_ChannelML",
 "m_forwardRate_midpoint_NaxSH10_ChannelML",
 "m_forwardRate_scale_NaxSH10_ChannelML",
 "m_reverseRate_rate_NaxSH10_ChannelML",
 "m_reverseRate_midpoint_NaxSH10_ChannelML",
 "m_reverseRate_scale_NaxSH10_ChannelML",
 "m_timeCourse_TIME_SCALE_NaxSH10_ChannelML",
 "m_timeCourse_VOLT_SCALE_NaxSH10_ChannelML",
 "m_q10Settings_q10Factor_NaxSH10_ChannelML",
 "m_q10Settings_experimentalTemp_NaxSH10_ChannelML",
 "m_q10Settings_TENDEGREES_NaxSH10_ChannelML",
 "h_instances_NaxSH10_ChannelML",
 "h_steadyState_rate_NaxSH10_ChannelML",
 "h_steadyState_midpoint_NaxSH10_ChannelML",
 "h_steadyState_scale_NaxSH10_ChannelML",
 "h_forwardRate_rate_NaxSH10_ChannelML",
 "h_forwardRate_midpoint_NaxSH10_ChannelML",
 "h_forwardRate_scale_NaxSH10_ChannelML",
 "h_reverseRate_rate_NaxSH10_ChannelML",
 "h_reverseRate_midpoint_NaxSH10_ChannelML",
 "h_reverseRate_scale_NaxSH10_ChannelML",
 "h_timeCourse_TIME_SCALE_NaxSH10_ChannelML",
 "h_timeCourse_VOLT_SCALE_NaxSH10_ChannelML",
 "h_q10Settings_q10Factor_NaxSH10_ChannelML",
 "h_q10Settings_experimentalTemp_NaxSH10_ChannelML",
 "h_q10Settings_TENDEGREES_NaxSH10_ChannelML",
 0,
 "gion_NaxSH10_ChannelML",
 "m_forwardRate_x_NaxSH10_ChannelML",
 "m_forwardRate_r_NaxSH10_ChannelML",
 "m_reverseRate_x_NaxSH10_ChannelML",
 "m_reverseRate_r_NaxSH10_ChannelML",
 "m_timeCourse_V_NaxSH10_ChannelML",
 "m_timeCourse_ALPHA_NaxSH10_ChannelML",
 "m_timeCourse_BETA_NaxSH10_ChannelML",
 "m_timeCourse_t_NaxSH10_ChannelML",
 "m_q10Settings_q10_NaxSH10_ChannelML",
 "m_rateScale_NaxSH10_ChannelML",
 "m_alpha_NaxSH10_ChannelML",
 "m_beta_NaxSH10_ChannelML",
 "m_fcond_NaxSH10_ChannelML",
 "m_inf_NaxSH10_ChannelML",
 "m_tauUnscaled_NaxSH10_ChannelML",
 "m_tau_NaxSH10_ChannelML",
 "h_steadyState_x_NaxSH10_ChannelML",
 "h_forwardRate_x_NaxSH10_ChannelML",
 "h_forwardRate_r_NaxSH10_ChannelML",
 "h_reverseRate_x_NaxSH10_ChannelML",
 "h_reverseRate_r_NaxSH10_ChannelML",
 "h_timeCourse_V_NaxSH10_ChannelML",
 "h_timeCourse_ALPHA_NaxSH10_ChannelML",
 "h_timeCourse_BETA_NaxSH10_ChannelML",
 "h_timeCourse_t_NaxSH10_ChannelML",
 "h_q10Settings_q10_NaxSH10_ChannelML",
 "h_rateScale_NaxSH10_ChannelML",
 "h_alpha_NaxSH10_ChannelML",
 "h_beta_NaxSH10_ChannelML",
 "h_inf_NaxSH10_ChannelML",
 "h_tauUnscaled_NaxSH10_ChannelML",
 "h_tau_NaxSH10_ChannelML",
 "h_fcond_NaxSH10_ChannelML",
 "conductanceScale_NaxSH10_ChannelML",
 "fopen0_NaxSH10_ChannelML",
 "fopen_NaxSH10_ChannelML",
 "g_NaxSH10_ChannelML",
 0,
 "m_q_NaxSH10_ChannelML",
 "h_q_NaxSH10_ChannelML",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 78, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	m_instances = 3;
 	m_forwardRate_rate = 2.88;
 	m_forwardRate_midpoint = -20;
 	m_forwardRate_scale = 7.2;
 	m_reverseRate_rate = 0.8928;
 	m_reverseRate_midpoint = -20;
 	m_reverseRate_scale = -7.2;
 	m_timeCourse_TIME_SCALE = 1;
 	m_timeCourse_VOLT_SCALE = 1;
 	m_q10Settings_q10Factor = 2;
 	m_q10Settings_experimentalTemp = 297.15;
 	m_q10Settings_TENDEGREES = 10;
 	h_instances = 1;
 	h_steadyState_rate = 1;
 	h_steadyState_midpoint = -40;
 	h_steadyState_scale = -4;
 	h_forwardRate_rate = 0.045;
 	h_forwardRate_midpoint = -35;
 	h_forwardRate_scale = 1.5;
 	h_reverseRate_rate = 0.015;
 	h_reverseRate_midpoint = -35;
 	h_reverseRate_scale = -1.5;
 	h_timeCourse_TIME_SCALE = 1;
 	h_timeCourse_VOLT_SCALE = 1;
 	h_q10Settings_q10Factor = 2;
 	h_q10Settings_experimentalTemp = 297.15;
 	h_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 78;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
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

 void _NaxSH10_ChannelML_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", 1.0);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 78, 3);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 NaxSH10_ChannelML /home/Simon/NML2_Test/AOB_mitral_cell/x86_64/NaxSH10_ChannelML.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=NaxSH10_ChannelML type=ionChannelHH)";

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
   Dh_q = rate_h_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Dm_q = Dm_q  / (1. - dt*( 0.0 )) ;
 Dh_q = Dh_q  / (1. - dt*( 0.0 )) ;
 return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    m_q = m_q - dt*(- ( rate_m_q ) ) ;
    h_q = h_q - dt*(- ( rate_h_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   m_forwardRate_x = ( v - m_forwardRate_midpoint ) / m_forwardRate_scale ;
   if ( m_forwardRate_x  != 0.0 ) {
     m_forwardRate_r = m_forwardRate_rate * m_forwardRate_x / ( 1.0 - exp ( 0.0 - m_forwardRate_x ) ) ;
     }
   else if ( m_forwardRate_x  == 0.0 ) {
     m_forwardRate_r = m_forwardRate_rate ;
     }
   m_reverseRate_x = ( v - m_reverseRate_midpoint ) / m_reverseRate_scale ;
   if ( m_reverseRate_x  != 0.0 ) {
     m_reverseRate_r = m_reverseRate_rate * m_reverseRate_x / ( 1.0 - exp ( 0.0 - m_reverseRate_x ) ) ;
     }
   else if ( m_reverseRate_x  == 0.0 ) {
     m_reverseRate_r = m_reverseRate_rate ;
     }
   m_timeCourse_V = v / m_timeCourse_VOLT_SCALE ;
   m_timeCourse_ALPHA = m_alpha * m_timeCourse_TIME_SCALE ;
   m_timeCourse_BETA = m_beta * m_timeCourse_TIME_SCALE ;
   if ( ( m_timeCourse_ALPHA + m_timeCourse_BETA )  == 0.0 ) {
     m_timeCourse_t = 0.0 * m_timeCourse_TIME_SCALE ;
     }
   else if ( 1.0 / ( ( m_timeCourse_ALPHA + m_timeCourse_BETA ) * m_rateScale ) < ( 0.02 ) ) {
     m_timeCourse_t = ( ( 0.02 * m_rateScale ) ) * m_timeCourse_TIME_SCALE ;
     }
   else {
     m_timeCourse_t = ( 1.0 / ( m_timeCourse_ALPHA + m_timeCourse_BETA ) ) * m_timeCourse_TIME_SCALE ;
     }
   m_q10Settings_q10 = pow( m_q10Settings_q10Factor , ( ( temperature - m_q10Settings_experimentalTemp ) / m_q10Settings_TENDEGREES ) ) ;
   m_rateScale = m_q10Settings_q10 ;
   m_alpha = m_forwardRate_r ;
   m_beta = m_reverseRate_r ;
   m_fcond = pow( m_q , m_instances ) ;
   m_inf = m_alpha / ( m_alpha + m_beta ) ;
   m_tauUnscaled = m_timeCourse_t ;
   m_tau = m_tauUnscaled / m_rateScale ;
   h_steadyState_x = h_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - h_steadyState_midpoint ) / h_steadyState_scale ) ) ;
   h_forwardRate_x = ( v - h_forwardRate_midpoint ) / h_forwardRate_scale ;
   if ( h_forwardRate_x  != 0.0 ) {
     h_forwardRate_r = h_forwardRate_rate * h_forwardRate_x / ( 1.0 - exp ( 0.0 - h_forwardRate_x ) ) ;
     }
   else if ( h_forwardRate_x  == 0.0 ) {
     h_forwardRate_r = h_forwardRate_rate ;
     }
   h_reverseRate_x = ( v - h_reverseRate_midpoint ) / h_reverseRate_scale ;
   if ( h_reverseRate_x  != 0.0 ) {
     h_reverseRate_r = h_reverseRate_rate * h_reverseRate_x / ( 1.0 - exp ( 0.0 - h_reverseRate_x ) ) ;
     }
   else if ( h_reverseRate_x  == 0.0 ) {
     h_reverseRate_r = h_reverseRate_rate ;
     }
   h_timeCourse_V = v / h_timeCourse_VOLT_SCALE ;
   h_timeCourse_ALPHA = h_alpha * h_timeCourse_TIME_SCALE ;
   h_timeCourse_BETA = h_beta * h_timeCourse_TIME_SCALE ;
   if ( ( h_timeCourse_ALPHA + h_timeCourse_BETA )  == 0.0 ) {
     h_timeCourse_t = 0.0 * h_timeCourse_TIME_SCALE ;
     }
   else if ( 1.0 / ( ( h_timeCourse_ALPHA + h_timeCourse_BETA ) * h_rateScale ) < ( 0.5 ) ) {
     h_timeCourse_t = ( ( 0.5 * h_rateScale ) ) * h_timeCourse_TIME_SCALE ;
     }
   else {
     h_timeCourse_t = ( 1.0 / ( h_timeCourse_ALPHA + h_timeCourse_BETA ) ) * h_timeCourse_TIME_SCALE ;
     }
   h_q10Settings_q10 = pow( h_q10Settings_q10Factor , ( ( temperature - h_q10Settings_experimentalTemp ) / h_q10Settings_TENDEGREES ) ) ;
   h_rateScale = h_q10Settings_q10 ;
   h_alpha = h_forwardRate_r ;
   h_beta = h_reverseRate_r ;
   h_inf = h_steadyState_x ;
   h_tauUnscaled = h_timeCourse_t ;
   h_tau = h_tauUnscaled / h_rateScale ;
   h_fcond = pow( h_q , h_instances ) ;
   rate_m_q = ( m_inf - m_q ) / m_tau ;
   rate_h_q = ( h_inf - h_q ) / h_tau ;
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
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h_q = h_q0;
  m_q = m_q0;
 {
   ena = 67.0 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   m_q = m_inf ;
   h_q = h_inf ;
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
   fopen0 = m_fcond * h_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ina = gion * ( v - ena ) ;
   }
 _current += ina;

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
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
 _slist1[1] = &(h_q) - _p;  _dlist1[1] = &(Dh_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
