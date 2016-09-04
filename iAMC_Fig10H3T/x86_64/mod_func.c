#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _BK_IAMC_ChannelML_reg(void);
extern void _CaV_R_iAMC_ChannelML_reg(void);
extern void _Gran_CaPool_98_reg(void);
extern void _KA_iAMC_ChannelML_reg(void);
extern void _Kdr_iAMC_ChannelML_reg(void);
extern void _LeakConductance_reg(void);
extern void _NaP_iAMC_ChannelML_reg(void);
extern void _NaxSH0_ChannelML_reg(void);
extern void _NaxSH10_ChannelML_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," BK_IAMC_ChannelML.mod");
    fprintf(stderr," CaV_R_iAMC_ChannelML.mod");
    fprintf(stderr," Gran_CaPool_98.mod");
    fprintf(stderr," KA_iAMC_ChannelML.mod");
    fprintf(stderr," Kdr_iAMC_ChannelML.mod");
    fprintf(stderr," LeakConductance.mod");
    fprintf(stderr," NaP_iAMC_ChannelML.mod");
    fprintf(stderr," NaxSH0_ChannelML.mod");
    fprintf(stderr," NaxSH10_ChannelML.mod");
    fprintf(stderr, "\n");
  }
  _BK_IAMC_ChannelML_reg();
  _CaV_R_iAMC_ChannelML_reg();
  _Gran_CaPool_98_reg();
  _KA_iAMC_ChannelML_reg();
  _Kdr_iAMC_ChannelML_reg();
  _LeakConductance_reg();
  _NaP_iAMC_ChannelML_reg();
  _NaxSH0_ChannelML_reg();
  _NaxSH10_ChannelML_reg();
}
