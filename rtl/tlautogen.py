"""
This file is part of tlautogen.

tlautogen is free software: you can redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

tlautogen is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with tlautogen. If not, see
<https://www.gnu.org/licenses/>.
"""
import sys
version = 0.1
def copyright() -> None:
    print(f"""tlautogen {version} \nCopyright (C) 2023 Ayuub Mohamud.\nThis is free software; see the source for copying conditions. There is NO\nwarranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.""")

copyright()
print(f"\n\n\ntlautogen: Generating SOC from specified file {sys.argv[1]}")