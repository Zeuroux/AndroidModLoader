#include <aml.h>
#include <ARMPatch.h>
#include <modslist.h>
#include <string>

extern std::string g_szAppName;
extern std::string g_szCfgPath;
const char* AML::GetCurrentGame()
{
    return g_szAppName.c_str();
}

const char* AML::GetConfigPath()
{
    return g_szCfgPath.c_str();
}

bool AML::HasMod(const char* szGUID)
{
    return modlist->HasMod(szGUID);
}

bool AML::HasModOfVersion(const char* szGUID, const char* szVersion)
{
    return modlist->HasModOfVersion(szGUID, szVersion);
}

uintptr_t AML::GetLib(const char* szLib)
{
    return ARMPatch::getLib(szLib);
}

uintptr_t AML::GetSym(uintptr_t handle, const char* sym)
{
    return ARMPatch::getSym(handle, sym);
}

void AML::Hook(void* handle, void* fnAddress, void** orgFnAddress)
{
    ARMPatch::hookInternal(handle, fnAddress, orgFnAddress);
}

void AML::HookPLT(void* handle, void* fnAddress, void** orgFnAddress)
{
    ARMPatch::hookPLTInternal(handle, fnAddress, orgFnAddress);
}

int AML::Unprot(uintptr_t handle, size_t len)
{
    return ARMPatch::unprotect(handle, len);
}

void AML::Write(uintptr_t dest, uintptr_t src, size_t size)
{
    ARMPatch::write(dest, src, size);
}

void AML::Read(uintptr_t src, uintptr_t dest, size_t size)
{
    ARMPatch::read(src, dest, size);
}

void AML::PlaceNOP(uintptr_t addr, size_t count)
{
    ARMPatch::NOP(addr, count);
}

void AML::PlaceJMP(uintptr_t addr, uintptr_t dest)
{
    ARMPatch::JMP(addr, dest);
}

void AML::PlaceRET(uintptr_t addr)
{
    ARMPatch::RET(addr);
}

static AML amlLocal;
IAML* aml = (IAML*)&amlLocal;