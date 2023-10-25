"""
This file is part of openPolaris.

openPolaris is free software: you can redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

openPolaris is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with tlautogen. If not, see
<https://www.gnu.org/licenses/>.
"""

def genEncMultiplexer(caseExpr: str, caseNum: int, output: str, input: str, bxtrct: int, default_val : str) -> str:
    text = ""
    text += f"""\talways_comb begin\n\t\tcasez ({caseExpr})"""
    comp_bitvec = []
    for x in range(0, caseNum):
        comp_bitvec.append('z')
    for x in range(0, caseNum):
        comp_bitvec[caseNum-x-1] = '1'
        for y in range (caseNum-x, caseNum):
            comp_bitvec[y] = '0'
        bitvec = "".join(comp_bitvec)
        text += f"\n\t\t\t{caseNum}'b{bitvec}: {output} = {input}[{(x+1)*bxtrct-1}:{(x)*bxtrct}];"
    text+=f"\n\t\t\tdefault: {output} = {default_val};\n\t\tendcase\n\tend"
    return text

