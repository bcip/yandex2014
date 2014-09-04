import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class PrecAF2 {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskGame solver = new TaskGame();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskGame {
    String allS = "1S165F1S5333F,79F1S109F1S1643F1S3667F,1S5501F,1F1S321F1S5179F,1S1099F1S733F1S3669F,611F1S4893F,1S83F1S5421F,423F1S1411F1S3671F,1S5507F,1101F1S4407F,1S1835F1S3673F,5511F,1S5511F,1F1S1835F1S3675F,1S611F1S489F1S4411F,5515F,1S261F1S1575F1S3677F,1F1S5515F,1S5517F,1103F1S735F1S3679F,1S323F1S99F1S5095F,5521F,1S1839F1S3681F,613F1S4909F,1S111F1S21F1S969F1S4419F,1841F1S3683F,1S5525F,5527F,1S1841F1S3685F,1F1S1103F1S4423F,1S189F1S5339F,1843F1S3687F,1S613F1S4917F,1F1S165F1S257F1S5107F,1S1105F1S737F1S3689F,5535F,1S5535F,1F1S261F1S61F1S1519F1S3691F,1S5537F,1107F1S4431F,1S1845F1S3693F,615F1S4925F,1S5541F,1847F1S3695F,1S1107F1S4435F,5545F,1S425F1S1421F1S3697F,1F1S5545F,1S5547F,1109F1S739F1S3699F,1S615F1S4933F,1F1S5549F,1S1849F1S3701F,5553F,1S325F1S783F1S4443F,1851F1S3703F,1S5555F,5557F,1S263F1S1587F1S3705F,191F1S235F1S189F1S493F1S4447F,1S5559F,1853F1S3707F,1S5561F,1F1S5561F,1S1111F1S741F1S3709F,135F1S5429F,1S167F1S5397F,1F1S1853F1S3711F,1S617F1S4949F,1113F1S4455F,1S79F1S1775F1S3713F,1F1S83F1S241F1S5243F,1S427F1S5143F,113F1S1743F1S3715F,1S1113F1S4459F,5575F,1S1857F1S3717F,619F1S4957F,1S5577F,265F1S849F1S743F1S3719F,1S5579F,1F1S5579F,1S1859F1S3721F,5583F,1S1115F1S4467F,1F1S427F1S1431F1S3723F,1S619F1S4965F,5587F,1S191F1S135F1S1533F1S3725F,1117F1S4471F,1S5589F,1863F1S3727F,1S5591F,5593F,1S1117F1S745F1S3729F,621F1S4973F,1S5595F,1F1S1863F1S3731F,1S429F1S5167F,169F1S949F1S4479F,1S265F1S1599F1S3733F,1F1S5599F,1S5601F,1867F1S3735F,1S621F1S497F1S4483F,1F1S327F1S5275F,1S135F1S1731F1S3737F,5607F,1S5607F,1121F1S747F1S3739F,1S5609F,431F1S5179F,1S1869F1S3741F,623F1S4989F,1S1121F1S4491F,1F1S1869F1S3743F,1S5615F,193F1S5423F,1S1871F1S3745F,1F1S1121F1S4495F,1S5619F,267F1S1605F1S3747F,1S113F1S215F1S293F1S4997F,5623F,1S431F1S691F1S749F1S3749F,5625F,1S5625F,1875F1S3751F,1S5627F,1125F1S4503F,1S1875F1S3753F,1F1S623F1S5005F,1S169F1S5461F,1877F1S3755F,1S1125F1S4507F,1F1S5633F,1S85F1S1791F1S3757F,433F1S5203F,1S5637F,1F1S79F1S249F1S795F1S751F1S3759F,1S625F1S5013F,5641F,1S267F1S1611F1S3761F,5643F,1S1127F1S4515F,1881F1S3763F,1S193F1S5451F,137F1S5509F,1S1881F1S3765F,1F1S625F1S501F1S4519F,1S433F1S5215F,1883F1S3767F,1S5651F,1F1S5651F,1S1129F1S753F1S3769F,5655F,1S331F1S5323F,1885F1S3771F,1S627F1S5029F,1131F1S4527F,1S1885F1S3773F,5661F,1S5661F,269F1S165F1S1451F1S3775F,1S1131F1S4531F,1F1S169F1S5493F,1S1887F1S3777F,629F1S5037F,1S5667F,1F1S1131F1S755F1S3779F,1S5669F,115F1S5555F,1S1889F1S3781F,1F1S331F1S5339F,1S1133F1S4539F,195F1S1695F1S3783F,1S435F1S193F1S5045F,5677F,1S1891F1S3785F,1135F1S4543F,1S5679F,1893F1S3787F,1S5681F,1F1S5681F,1S269F1S865F1S757F1S3789F,631F1S5053F,1S5685F,1F1S1893F1S3791F,1S137F1S5549F,437F1S699F1S4551F,1S333F1S1561F1S3793F,5691F,1S5691F,1897F1S3795F,1S631F1S505F1S4555F,5695F,1S1897F1S3797F,5697F,1S171F1S5525F,1F1S1137F1S759F1S3799F,1S5699F,87F1S5613F,1S437F1S1461F1S3801F,1F1S631F1S5069F,1S195F1S943F1S4563F,271F1S1629F1S3803F,1S5705F,1F1S333F1S5371F,1S81F1S1819F1S3805F,1141F1S4567F,1S5709F,1903F1S3807F,1S633F1S5077F,5713F,1S1141F1S761F1S3809F,439F1S5275F,1S5715F,1F1S1903F1S3811F,1S5717F,1143F1S4575F,1S115F1S1789F1S3813F,1F1S633F1S5085F,1S5721F,1907F1S3815F,1S335F1S807F1S4579F,5725F,1S271F1S1635F1S3817F,5727F,1S439F1S5287F,139F1S1005F1S763F1S3819F,1S635F1S5093F,173F1S5557F,1S1909F1S3821F,1F1S195F1S5535F,1S1145F1S4587F,1911F1S3823F,1S5735F,1F1S5735F,1S1911F1S3825F,637F1S509F1S4591F,1S5739F,1F1S335F1S103F1S1471F1S3827F,1S5741F,5743F,1S1147F1S765F1S3829F,5745F,1S5745F,273F1S1641F1S3831F,1S637F1S5109F,1149F1S4599F,1S1915F1S3833F,1F1S5749F,1S5751F,1917F1S3835F,1S441F1S707F1S4603F,1F1S5753F,1S1917F1S3837F,639F1S5117F,1S337F1S5419F,1151F1S767F1S3839F,1S5759F,5761F,1S197F1S1721F1S3841F,5763F,1S173F1S977F1S4611F,1921F1S3843F,1S87F1S551F1S5125F,1F1S441F1S5323F,1S273F1S1647F1S3845F,117F1S1035F1S4615F,1S139F1S5629F,1F1S1921F1S3847F,1S5771F,5773F,1S1153F1S769F1S3849F,1F1S337F1S301F1S5133F,1S5775F,83F1S1841F1S3851F,1S5777F,1155F1S4623F,1S443F1S1481F1S3853F,5781F,1S5781F,1927F1S3855F,1S641F1S513F1S4627F,1F1S5783F,1S1927F1S3857F,5787F,1S5787F,1F1S273F1S881F1S771F1S3859F,1S5789F,199F1S5591F,1S339F1S1589F1S3861F,445F1S197F1S5149F,1S1157F1S4635F,1931F1S3863F,1S5795F,175F1S5621F,1S1931F1S3865F,1159F1S4639F,1S5799F,1F1S1931F1S3867F,1S643F1S5157F,5803F,1S1159F1S773F1S3869F,1F1S5803F,1S445F1S5359F,1935F1S3871F,1S5807F,1F1S339F1S819F1S4647F,1S275F1S1659F1S3873F,141F1S503F1S5165F,1S5811F,1937F1S3875F,1S1161F1S4651F,5815F,1S1937F1S3877F,5817F,1S117F1S5699F,1F1S445F1S715F1S775F1S3879F,1S199F1S445F1S5173F,5821F,1S1939F1S3881F,1F1S5821F,1S1163F1S4659F,1941F1S3883F,1S341F1S5483F,5827F,1S1941F1S3885F,647F1S517F1S4663F,1S175F1S5653F,89F1S187F1S1665F1S3887F,1S447F1S5383F,5833F,1S13F1S1151F1S777F1S3889F,1F1S5833F,1S5835F,1945F1S3891F,1S647F1S5189F,1F1S1165F1S4671F,1S1945F1S3893F,5841F,1S5841F,1F1S341F1S1603F1S3895F,1S1167F1S4675F,449F1S5395F,1S83F1S1863F1S3897F,649F1S5197F,1S5847F,201F1S967F1S779F1S3899F,1S5849F,5851F,1S141F1S135F1S1671F1S3901F,1F1S5851F,1S1169F1S4683F,1951F1S3903F,1S649F1S5205F,1F1S5855F,1S449F1S1501F1S3905F,1171F1S4687F,1S343F1S5515F,1953F1S3907F,1S5861F,177F1S5685F,1S1171F1S781F1S3909F,651F1S5213F,1S5865F,119F1S1835F1S3911F,1S5867F,1F1S1171F1S4695F,1S1955F1S3913F,451F1S5419F,1S5871F,1F1S277F1S1677F1S3915F,1S651F1S521F1S4699F,5875F,1S1957F1S3917F,1F1S343F1S5531F,1S201F1S5675F,1175F1S783F1S3919F,1S5879F,5881F,1S1959F1S3921F,653F1S5229F,1S451F1S723F1S4707F,1961F1S3923F,1S5885F,1F1S5885F,1S1961F1S3925F,1177F1S4711F,1S5889F,1F1S1961F1S3927F,1S653F1S5237F,143F1S5749F,1S279F1S65F1S831F1S785F1S3929F,5895F,1S89F1S87F1S5717F,453F1S1511F1S3931F,1S5897F,1179F1S4719F,1S1965F1S3933F,655F1S5245F,1S5901F,1F1S1965F1S3935F,1S1179F1S4723F,5905F,1S1967F1S3937F,1F1S201F1S5703F,1S5907F,1181F1S787F1S3939F,1S453F1S201F1S5253F,1F1S345F1S5563F,1S1969F1S3941F,5913F,1S1181F1S4731F,85F1S195F1S1689F1S3943F,1S119F1S5795F,5917F,1S1971F1S3945F,657F1S525F1S4735F,1S5919F,1F1S1971F1S3947F,1S5921F,455F1S5467F,1S1183F1S789F1S3949F,1F1S5923F,1S5925F,1975F1S3951F,1S347F1S309F1S5269F,179F1S1005F1S4743F,1S1975F1S3953F,5931F,1S5931F,1977F1S3955F,1S143F1S1041F1S4747F,5935F,1S203F1S77F1S173F1S1521F1S3957F,1F1S657F1S5277F,1S5937F,1187F1S791F1S3959F,1S5939F,1F1S5939F,1S1979F1S3961F,5943F,1S1187F1S4755F,1F1S347F1S1631F1S3963F,1S659F1S5285F,5947F,1S1981F1S3965F,457F1S731F1S4759F,1S5949F,1983F1S3967F,1S5951F,5953F,1S1189F1S793F1S3969F,1F1S659F1S5293F,1S5955F,283F1S1701F1S3971F,1S5957F,1F1S1189F1S4767F,1S1985F1S3973F,91F1S5869F,1S179F1S169F1S107F1S5503F,1987F1S3975F,1S661F1S529F1S4771F,121F1S83F1S5759F,1S1987F1S3977F,5967F,1S5967F,1193F1S795F1S3979F,1S5969F,1F1S5969F,1S1989F1S3981F,663F1S5309F,1S1193F1S4779F,1F1S143F1S313F1S1531F1S3983F,1S5975F,5977F,1S283F1S1707F1S3985F,1F1S349F1S843F1S4783F,1S5979F,1993F1S3987F,1S663F1S5317F,5983F,1S85F1S1109F1S797F1S3989F,5985F,1S5985F,1995F1S3991F,1S459F1S5527F,1F1S1195F1S4791F,1S1995F1S3993F,665F1S5325F,1S5991F,1F1S1995F1S3995F,1S205F1S991F1S4795F,181F1S5813F,1S351F1S1645F1S3997F,5997F,1S5997F,285F1S913F1S799F1S3999F,1S665F1S5333F,461F1S5539F,1S1999F1S4001F,6003F,1S1199F1S4803F,1F1S1999F1S4003F,1S6005F,6007F,1S2001F1S4005F,1F1S665F1S533F1S4807F,1S6009F,2003F1S4007F,1S6011F,1F1S351F1S5659F,1S121F1S339F1S739F1S801F1S4009F,6015F,1S145F1S5869F,2005F1S4011F,1S667F1S5349F,1203F1S4815F,1S285F1S1719F1S4013F,6021F,1S6021F,1F1S205F1S1799F1S4015F,1S1203F1S4819F,6025F,1S91F1S1915F1S4017F,1F1S461F1S205F1S5357F,1S181F1S5845F,1205F1S803F1S4019F,1S353F1S5675F,6031F,1S2009F1S4021F,6033F,1S1205F1S4827F,2011F1S4023F,1S669F1S5365F,6037F,1S2011F1S4025F,1F1S1205F1S4831F,1S463F1S5575F,287F1S1725F1S4027F,1S6041F,1F1S6041F,1S1207F1S805F1S4029F,671F1S5373F,1S6045F,1F1S353F1S1659F1S4031F,1S6047F,1209F1S4839F,1S2015F1S4033F,6051F,1S207F1S5843F,87F1S377F1S1551F1S4035F,1S671F1S537F1S4843F,6055F,1S2017F1S4037F,1F1S145F1S5909F,1S6057F,1211F1S807F1S4039F,1S6059F,1F1S181F1S5877F,1S287F1S1731F1S4041F,123F1S549F1S5389F,1S355F1S855F1S4851F,2021F1S4043F,1S465F1S5599F,6067F,1S2021F1S4045F,1213F1S4855F,1S6069F,2023F1S4047F,1S673F1S5397F,1F1S6071F,1S1213F1S809F1S4049F,6075F,1S6075F,1F1S2023F1S4051F,1S6077F,467F1S747F1S4863F,1S2025F1S4053F,1F1S207F1S147F1S317F1S5405F,1S6081F,289F1S1737F1S4055F,1S1215F1S4867F,6085F,1S2027F1S4057F,6087F,1S6087F,1217F1S811F1S4059F,1S675F1S5413F,1F1S91F1S5997F,1S467F1S1561F1S4061F,6093F,1S183F1S1033F1S4875F,1F1S2029F1S4063F,1S6095F,6097F,1S147F1S209F1S1673F1S4065F,677F1S541F1S4879F,1S6099F,2033F1S4067F,1S6101F,6103F,1S289F1S929F1S813F1S4069F,469F1S5635F,1S6105F,1F1S2033F1S4071F,1S677F1S5429F,1221F1S4887F,1S209F1S1825F1S4073F,1F1S6109F,1S123F1S5987F,2037F1S4075F,1S1221F1S4891F,1F1S357F1S5755F,1S2037F1S4077F,679F1S5437F,1S469F1S5647F,1223F1S815F1S4079F,1S6119F,6121F,1S87F1S1951F1S4081F,6123F,1S1223F1S4899F,1F1S289F1S1749F1S4083F,1S679F1S5445F,185F1S5941F,1S2041F1S4085F,1F1S1223F1S4903F,1S6129F,471F1S1571F1S4087F,1S359F1S5771F,6133F,1S1225F1S817F1S4089F,681F1S5453F,1S6135F,2045F1S4091F,1S6137F,149F1S61F1S1015F1S4911F,1S2045F1S4093F,1F1S6139F,1S6141F,2047F1S4095F,1S471F1S209F1S545F1S4915F,1F1S6143F,1S291F1S1755F1S4097F,6147F,1S6147F,1F1S359F1S867F1S819F1S4099F,1S6149F,6151F,1S2049F1S4101F,683F1S5469F,1S1229F1S4923F,2051F1S4103F,1S93F1S6061F,473F1S5683F,1S2051F1S4105F,1F1S1229F1S4927F,1S185F1S5973F,125F1S1927F1S4107F,1S683F1S5477F,1F1S6161F,1S1231F1S821F1S4109F,6165F,1S361F1S5803F,293F1S1761F1S4111F,1S211F1S5955F,1233F1S4935F,1S473F1S1581F1S4113F,685F1S5485F,1S6171F,2057F1S4115F,1S1233F1S4939F,1F1S6173F,1S2057F1S4117F,6177F,1S6177F,1F1S1233F1S823F1S4119F,1S149F1S535F1S5493F,6181F,1S2059F1S4121F,1F1S361F1S111F1S5707F,1S1235F1S4947F,2061F1S4123F,1S6185F,6187F,1S293F1S1767F1S4125F,687F1S549F1S4951F,1S6189F,89F1S1973F1S4127F,1S6191F,1F1S185F1S6005F,1S1237F1S825F1S4129F,6195F,1S475F1S5719F,1F1S211F1S1851F1S4131F,1S687F1S5509F,1239F1S4959F,1S363F1S1701F1S4133F,6201F,1S6201F,2067F1S4135F,1S1239F1S4963F,6205F,1S2067F1S4137F,689F1S5517F,1S6207F,1F1S293F1S181F1S763F1S827F1S4139F,1S125F1S6083F,6211F,1S2069F1S4141F,1F1S6211F,1S1241F1S4971F,2071F1S4143F,1S689F1S5525F,1F1S363F1S5851F,1S2071F1S4145F,1243F1S4975F,1S6219F,95F1S55F1S1921F1S4147F,1S477F1S5743F,6223F,1S1243F1S829F1S4149F,691F1S5533F,1S187F1S25F1S6011F,1F1S2073F1S4151F,1S6227F,1245F1S4983F,1S295F1S1779F1S4153F,1F1S13F1S6215F,1S6231F,2077F1S4155F,1S365F1S325F1S553F1S4987F,479F1S5755F,1S2077F1S4157F,6237F,1S6237F,1247F1S831F1S4159F,1S6239F,6241F,1S2079F1S4161F,1F1S691F1S5549F,1S1247F1S4995F,2081F1S4163F,1S6245F,1F1S6245F,1S479F1S1601F1S4165F,1249F1S4999F,1S6249F,1F1S295F1S69F1S1715F1S4167F,1S693F1S5557F,6253F,1S1249F1S833F1S4169F,215F1S6039F,1S6255F,2085F1S4171F,1S6257F,127F1S61F1S1061F1S5007F,1S89F1S1995F1S4173F,1F1S479F1S213F1S5565F,1S151F1S6109F,2087F1S4175F,1S1251F1S5011F,1F1S6263F,1S2087F1S4177F,6267F,1S367F1S5899F,1253F1S835F1S4179F,1S695F1S5573F,6271F,1S297F1S1791F1S4181F,6273F,1S481F1S771F1S5019F,2091F1S4183F,1S6275F,1F1S6275F,1S2091F1S4185F,697F1S557F1S5023F,1S6279F,1F1S2091F1S4187F,1S6281F,6283F,1S215F1S1039F1S837F1S4189F,1F1S367F1S5915F,1S95F1S6189F,483F1S1611F1S4191F,1S697F1S5589F,1257F1S5031F,1S2095F1S4193F,6291F,1S189F1S6101F,299F1S1797F1S4195F,1S1257F1S5035F,1F1S6293F,1S2097F1S4197F,699F1S5597F,1S6297F,1F1S1257F1S839F1S4199F,1S483F1S5815F,6301F,1S369F1S1729F1S4201F,153F1S6149F,1S1259F1S5043F,2101F1S4203F,1S699F1S5605F,6307F,1S127F1S1973F1S4205F,1261F1S5047F,1S6309F,1F1S2101F1S4207F,1S6311F,217F1S267F1S5827F,1S299F1S961F1S841F1S4209F,1F1S699F1S5613F,1S6315F,2105F1S4211F,1S6317F,1F1S369F1S891F1S5055F,1S2105F1S4213F,6321F,1S6321F,2107F1S4215F,1S701F1S561F1S5059F,191F1S6133F,1S485F1S1621F1S4217F,6327F,1S6327F,1F1S89F1S1173F1S843F1S4219F,1S6329F,6331F,1S2109F1S4221F,1F1S701F1S5629F,1S1265F1S5067F,301F1S1809F1S4223F,1S371F1S5963F,6337F,1S2111F1S4225F,487F1S779F1S5071F,1S6339F,2113F1S4227F,1S217F1S485F1S5637F,6343F,1S153F1S1113F1S845F1S4229F,1F1S6343F,1S6345F,2115F1S4231F,1S6347F,1F1S1267F1S5079F,1S2115F1S4233F,97F1S607F1S5645F,1S487F1S5863F,1F1S371F1S1743F1S4235F,1S1269F1S5083F,6355F,1S301F1S1815F1S4237F,129F1S6227F,1S191F1S6165F,1271F1S847F1S4239F,1S705F1S5653F,6361F,1S2119F1S4241F,1F1S6361F,1S1271F1S5091F,489F1S1631F1S4243F,1S6365F,1F1S6365F,1S2121F1S4245F,707F1S565F1S5095F,1S373F1S5995F,219F1S1903F1S4247F,1S6371F,6373F,1S1273F1S849F1S4249F,6375F,1S6375F,303F1S1821F1S4251F,1S489F1S217F1S5669F,1F1S1273F1S5103F,1S2125F1S4253F,6381F,1S6381F,1F1S2125F1S4255F,1S1275F1S5107F,155F1S6229F,1S2127F1S4257F,1F1S373F1S333F1S5677F,1S6387F,1277F1S851F1S4259F,1S6389F,193F1S297F1S5899F,1S2129F1S4261F,6393F,1S1277F1S5115F,2131F1S4263F,1S709F1S5685F,1F1S6395F,1S91F1S211F1S1827F1S4265F,1279F1S5119F,1S219F1S6179F,1F1S2131F1S4267F,1S6401F,6403F,1S375F1S115F1S787F1S853F1S4269F,711F1S5693F,1S129F1S6275F,2135F1S4271F,1S6407F,1281F1S5127F,1S2135F1S4273F,6411F,1S6411F,1F1S2135F1S4275F,1S711F1S569F1S5131F,6415F,1S97F1S2039F1S4277F,1F1S491F1S5923F,1S6417F,305F1S977F1S855F1S4279F,1S6419F,1F1S375F1S6043F,1S2139F1S4281F,713F1S5709F,1S193F1S1089F1S5139F,2141F1S4283F,1S155F1S6269F,6427F,1S2141F1S4285F,221F1S1063F1S5143F,1S493F1S5935F,1F1S2141F1S4287F,1S713F1S5717F,6433F,1S1285F1S857F1S4289F,1F1S6433F,1S6435F,2145F1S4291F,1S377F1S6059F,1287F1S5151F,1S305F1S1839F1S4293F,715F1S5725F,1S6441F,495F1S1651F1S4295F,1S1287F1S5155F,6445F,1S2147F1S4297F,1F1S6445F,1S6447F,1289F1S859F1S4299F,1S715F1S5733F,1F1S6449F,1S2149F1S4301F,6453F,1S1289F1S5163F,1F1S129F1S247F1S1771F1S4303F,1S495F1S5959F,195F1S6261F,1S221F1S1929F1S4305F,717F1S573F1S5167F,1S6459F,307F1S1845F1S4307F,1S6461F,6463F,1S1291F1S861F1S4309F,1F1S6463F,1S6465F,93F1S63F1S1997F1S4311F,1S717F1S5749F,1F1S495F1S795F1S5175F,1S2155F1S4313F,6471F,1S379F1S6091F,2157F1S4315F,1S1293F1S5179F,6475F,1S2157F1S4317F,719F1S5757F,1S6477F,1295F1S863F1S4319F,1S6479F,1F1S97F1S6381F,1S307F1S189F1S1661F1S4321F,6483F,1S1295F1S5187F,1F1S2159F1S4323F,1S719F1S5765F,223F1S6263F,1S2161F1S4325F,1F1S379F1S915F1S5191F,1S195F1S6293F,2163F1S4327F,1S6491F,6493F,1S1297F1S865F1S4329F,499F1S221F1S5773F,1S6495F,2165F1S4331F,1S6497F,1F1S1297F1S5199F,1S2165F1S4333F,6501F,1S6501F,1F1S307F1S1857F1S4335F,1S131F1S589F1S577F1S5203F,6505F,1S381F1S1785F1S4337F,6507F,1S157F1S341F1S6007F,1301F1S867F1S4339F,1S6509F,6511F,1S2169F1S4341F,723F1S5789F,1S1301F1S5211F,1F1S2169F1S4343F,1S223F1S6291F,6517F,1S2171F1S4345F,1F1S1301F1S5215F,1S6519F,501F1S1671F1S4347F,1S723F1S5797F,1F1S195F1S185F1S6139F,1S309F1S993F1S869F1S4349F,6525F,1S6525F,2175F1S4351F,1S6527F,1305F1S5223F,1S2175F1S4353F,725F1S5805F,1S6531F,1F1S2175F1S4355F,1S501F1S803F1S5227F,6535F,1S93F1S2083F1S4357F,1F1S6535F,1S6537F,1307F1S871F1S4359F,1S383F1S341F1S5813F,6541F,1S2179F1S4361F,6543F,1S1307F1S5235F,225F1S85F1S1869F1S4363F,1S99F1S6445F,503F1S6043F,1S2181F1S4365F,1F1S157F1S567F1S581F1S5239F,1S6549F,2183F1S4367F,1S6551F,1F1S131F1S6419F,1S1309F1S873F1S4369F,6555F,1S197F1S6357F,1F1S383F1S1799F1S4371F,1S727F1S5829F,1311F1S5247F,1S503F1S1681F1S4373F,6561F,1S6561F,2187F1S4375F,1S1311F1S5251F,6565F,1S311F1S1875F1S4377F,1F1S727F1S5837F,1S6567F,1313F1S875F1S4379F,1S6569F,1F1S6569F,1S2189F1S4381F,505F1S6067F,1S225F1S159F1S927F1S5259F,2191F1S4383F,1S729F1S5845F,6577F,1S2191F1S4385F,1315F1S5263F,1S6579F,2193F1S4387F,1S6581F,1F1S6581F,1S1315F1S877F1S4389F,731F1S5853F,1S505F1S6079F,1F1S311F1S1881F1S4391F,1S6587F,199F1S1117F1S5271F,1S159F1S2035F1S4393F,1F1S385F1S6203F,1S6591F,2197F1S4395F,1S731F1S585F1S5275F,6595F,1S2197F1S4397F,6597F,1S6597F,507F1S811F1S879F1S4399F,1S6599F,1F1S6599F,1S133F1S2065F1S4401F,227F1S505F1S5869F,1S1319F1S5283F,1F1S93F1S2105F1S4403F,1S6605F,6607F,1S313F1S73F1S1813F1S4405F,1321F1S5287F,1S6609F,101F1S2101F1S4407F,1S507F1S225F1S5877F,6613F,1S1321F1S881F1S4409F,6615F,1S6615F,1F1S2203F1S4411F,1S6617F,1323F1S5295F,1S2205F1S4413F,1F1S733F1S5885F,1S199F1S6421F,2207F1S4415F,1S1323F1S5299F,1F1S387F1S119F1S6115F,1S2207F1S4417F,6627F,1S15F1S6611F,315F1S1009F1S883F1S4419F,1S735F1S5893F,161F1S6469F,1S227F1S1981F1S4421F,6633F,1S1325F1S5307F,1F1S2209F1S4423F,1S6635F,6637F,1S509F1S1701F1S4425F,1F1S735F1S589F1S5311F,1S6639F,2213F1S4427F,1S389F1S6251F,6643F,1S1327F1S885F1S4429F,6645F,1S6645F,2215F1S4431F,1S737F1S5909F,1329F1S5319F,1S315F1S1899F1S4433F,1F1S133F1S375F1S6139F,1S6651F,2217F1S4435F,1S1329F1S5323F,1F1S199F1S6453F,1S2217F1S4437F,739F1S5917F,1S6657F,1F1S389F1S939F1S887F1S4439F,1S6659F,229F1S6431F,1S2219F1S4441F,6663F,1S511F1S819F1S5331F,2221F1S4443F,1S739F1S5925F,6667F,1S2221F1S4445F,1F1S1331F1S5335F,1S6669F,317F1S1905F1S4447F,1S161F1S6509F,1F1S6671F,1S95F1S1237F1S889F1S4449F,741F1S5933F,1S101F1S289F1S6283F,513F1S1711F1S4451F,1S6677F,1335F1S5343F,1S2225F1S4453F,6681F,1S6681F,2227F1S4455F,1S741F1S593F1S5347F,1F1S6683F,1S2227F1S4457F,6687F,1S201F1S6485F,1F1S1335F1S891F1S4459F,1S229F1S283F1S6175F,6691F,1S317F1S1911F1S4461F,1F1S391F1S349F1S5949F,1S1337F1S5355F,2231F1S4463F,1S6695F,6697F,1S2231F1S4465F,1339F1S5359F,1S135F1S6563F,2233F1S4467F,1S743F1S5957F,1F1S513F1S6187F,1S1339F1S893F1S4469F,6705F,1S6705F,1F1S2233F1S4471F,1S6707F,1341F1S5367F,1S393F1S1841F1S4473F,745F1S5965F,1S6711F,163F1S155F1S1917F1S4475F,1S1341F1S5371F,6715F,1S515F1S1721F1S4477F,6717F,1S6717F,1F1S229F1S1111F1S895F1S4479F,1S745F1S5973F,203F1S6517F,1S2239F1S4481F,1F1S6721F,1S1343F1S5379F,2241F1S4483F,1S6725F,1F1S393F1S6331F,1S2241F1S4485F,517F1S229F1S597F1S5383F,1S6729F,2243F1S4487F,1S6731F,6733F,1S319F1S1025F1S897F1S4489F,6735F,1S6735F,1F1S2243F1S4491F,1S747F1S5989F,1347F1S5391F,1S2245F1S4493F,1F1S101F1S6637F,1S517F1S6223F,97F1S2149F1S4495F,1S395F1S951F1S5395F,6745F,1S2247F1S4497F,749F1S5997F,1S231F1S6515F,137F1S1211F1S899F1S4499F,1S6749F,6751F,1S2249F1S4501F,1F1S6751F,1S163F1S39F1S1145F1S5403F,321F1S197F1S1731F1S4503F,1S749F1S6005F,1F1S6755F,1S2251F1S4505F,1351F1S5407F,1S6759F,1F1S395F1S1855F1S4507F,1S6761F,6763F,1S1351F1S901F1S4509F,751F1S6013F,1S6765F,2255F1S4511F,1S519F1S6247F,1353F1S5415F,1S2255F1S4513F,1F1S6769F,1S6771F,2257F1S4515F,1S751F1S601F1S5419F,1F1S6773F,1S321F1S1935F1S4517F,233F1S6543F,1S397F1S6379F,1355F1S903F1S4519F,1S6779F,521F1S6259F,1S2259F1S4521F,753F1S6029F,1S1355F1S5427F,2261F1S4523F,1S6785F,1F1S203F1S6581F,1S2261F1S4525F,1357F1S5431F,1S6789F,1F1S2261F1S4527F,1S753F1S6037F,6793F,1S521F1S835F1S905F1S4529F,1F1S163F1S233F1S6395F,1S6795F,323F1S1941F1S4531F,1S137F1S6659F,1359F1S5439F,1S2265F1S4533F,755F1S6045F,1S6801F,2267F1S4535F,1S1359F1S5443F,1F1S6803F,1S103F1S129F1S2033F1S4537F,523F1S6283F,1S6807F,1F1S1359F1S907F1S4539F,1S755F1S6053F,6811F,1S97F1S301F1S1869F1S4541F,6813F,1S1361F1S5451F,2271F1S4543F,1S6815F,6817F,1S323F1S1947F1S4545F,757F1S605F1S5455F,1S205F1S317F1S6295F,1F1S2271F1S4547F,1S6821F,6823F,1S1363F1S909F1S4549F,1F1S6823F,1S6825F,2275F1S4551F,1S757F1S6069F,1F1S399F1S963F1S5463F,1S2275F1S4553F,6831F,1S6831F,525F1S1751F1S4555F,1S1365F1S5467F,235F1S6599F,1S165F1S2111F1S4557F,759F1S6077F,1S6837F,1F1S323F1S1041F1S911F1S4559F,1S6839F,6841F,1S2279F1S4561F,1F1S6841F,1S1367F1S5475F,2281F1S4563F,1S401F1S123F1S233F1S6085F,139F1S6707F,1S2281F1S4565F,1369F1S5479F,1S6849F,2283F1S4567F,1S6851F,207F1S6645F,1S1369F1S913F1S4569F,1F1S759F1S6093F,1S6855F,2285F1S4571F,1S6857F,1F1S525F1S843F1S5487F,1S325F1S1959F1S4573F,6861F,1S6861F,1F1S401F1S1883F1S4575F,1S235F1S525F1S609F1S5491F,6865F,1S2287F1S4577F,6867F,1S6867F,1373F1S915F1S4579F,1S6869F,105F1S6765F,1S527F1S1761F1S4581F,1F1S761F1S6109F,1S1373F1S5499F,2291F1S4583F,1S6875F,1F1S165F1S6709F,1S2291F1S4585F,1375F1S5503F,1S403F1S6475F,99F1S227F1S1965F1S4587F,1S763F1S6117F,6883F,1S1375F1S917F1S4589F,529F1S6355F,1S207F1S6677F,2295F1S4591F,1S6887F,1F1S1375F1S5511F,1S2295F1S4593F,765F1S6125F,1S6891F,1F1S235F1S2059F1S4595F,1S1377F1S5515F,6895F,1S139F1S2157F1S4597F,1F1S403F1S6491F,1S529F1S6367F,1379F1S919F1S4599F,1S765F1S6133F,6901F,1S327F1S1971F1S4601F,6903F,1S1379F1S5523F,2301F1S4603F,1S6905F,1F1S6905F,1S2301F1S4605F,767F1S613F1S5527F,1S6909F,1F1S529F1S1771F1S4607F,1S6911F,6913F,1S405F1S975F1S921F1S4609F,6915F,1S6915F,2305F1S4611F,1S167F1S599F1S6149F,209F1S1173F1S5535F,1S2305F1S4613F,6921F,1S237F1S6683F,1F1S327F1S1977F1S4615F,1S531F1S851F1S5539F,6925F,1S2307F1S4617F,1F1S767F1S6157F,1S6927F,1385F1S923F1S4619F,1S6929F,1F1S405F1S6523F,1S2309F1S4621F,6933F,1S1385F1S5547F,2311F1S4623F,1S105F1S663F1S6165F,533F1S6403F,1S2311F1S4625F,1387F1S5551F,1S6939F,1F1S2311F1S4627F,1S6941F,6943F,1S329F1S1057F1S925F1S4629F,1F1S139F1S629F1S6173F,1S6945F,2315F1S4631F,1S407F1S6539F,1389F1S5559F,1S99F1S433F1S1781F1S4633F,239F1S6711F,1S209F1S6741F,2317F1S4635F,1S771F1S617F1S5563F,6955F,1S2317F1S4637F,1F1S6955F,1S6957F,169F1S1221F1S927F1S4639F,1S6959F,1F1S6959F,1S2319F1S4641F,535F1S237F1S6189F,1S1391F1S5571F,1F1S329F1S77F1S1911F1S4643F,1S6965F,6967F,1S2321F1S4645F,1393F1S5575F,1S6969F,2323F1S4647F,1S773F1S6197F,6973F,1S1393F1S929F1S4649F,1F1S6973F,1S535F1S6439F,2325F1S4651F,1S6977F,1F1S1393F1S5583F,1S239F1S2085F1S4653F,775F1S6205F,1S409F1S6571F,2327F1S4655F,1S1395F1S5587F,211F1S6773F,1S331F1S1995F1S4657F,6987F,1S6987F,537F1S859F1S931F1S4659F,1S775F1S6213F,1F1S6989F,1S2329F1S4661F,6993F,1S141F1S1255F1S5595F,1F1S2329F1S4663F,1S6995F,6997F,1S2331F1S4665F,1F1S409F1S365F1S621F1S5599F,1S169F1S6829F";

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        if (n >= 5500) {
            n -= 5500;
            String[] tokens = allS.split(",");
            out.println(decompress(tokens[n]));
            return;
        }
        TreeSet<Integer> candidates = new TreeSet<Integer>();
        for (int i = 1; i <= n; i++) {
            int value = n / i + 1;
            if (value + value <= n) {
                candidates.add(n / i + 1);
            }
        }
        candidates.add(1);
        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < n; ++i) {
            ans.append('F');
        }
        int us = 0;
        int[] um = new int[n + 1];
        int[] dp = new int[n + 1];
        for (int candidate : candidates) {
            for (int i = 0; i < candidate; ++i) {
                dp[i] = 0;
            }
            for (int i = candidate; i <= n; ++i) {
                ++us;
                for (int j = 0; j <= i - j - candidate; ++j) {
                    int v = (dp[j] ^ dp[i - j - candidate]);
                    um[v] = us;
                }

                for (int j = 0; ; ++j) {
                    if (um[j] != us) {
                        dp[i] = j;
                        break;
                    }
                }
            }

            if (dp[n] == 0) {
                ans.setCharAt(candidate - 1, 'S');
            }
        }
        out.println(ans.toString());
    }

    String decompress(String s) {
        int x = 0;
        StringBuilder b = new StringBuilder("");
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                x = x * 10 + (s.charAt(i) - '0');
            } else {
                char c = s.charAt(i);
                for (int j = 0; j < x; ++j) {
                    b.append(c);
                }
                x = 0;
            }
        }
        return b.toString();
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine().trim();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

}

