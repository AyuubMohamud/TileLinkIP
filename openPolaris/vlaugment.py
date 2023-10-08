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

def openPolarisSelect(match: list, replace: list, text: str) -> str:
    textReplacement = list(text)
    finished = False
    innerFinished = False
    x = 0
    temp = 0
    matchString = ""
    while not finished and not x==len(text) and not x+1==len(text) and not x+2==len(text):
        if text[x]=='/' and text[x+1]=='*' and text[x+2]==' ':
            temp = x
            x = x+3
            matchString.append("/* ")
            while text[x] != '/':
                matchString.append(text[x])
                x+=1
            matchString.append("/")



        x += 1
    return ""