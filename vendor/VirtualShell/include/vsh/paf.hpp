#ifndef __PAF_HPP__
#define __PAF_HPP__

#include "vsh/stdc.hpp"
#include <string>

namespace paf
{
    // some paf exports are vec operators so i guess i'll just put the vec classes here for now

    class vec2
    {
    public:
        union {
            float v[2];
            struct { float x, y; };
        };

        vec2()
            : x(0), y(0) {}

        vec2(float x, float y)
            : x(x), y(y) {}

        vec2(float vec[2]) {
            if (vec)
                x = vec[0], y = vec[1];
            else
                *this = vec2();
        }

        vec2 operator+(const vec2 vec) {
            return vec2(x + vec.x, y + vec.y);
        }

        vec2 operator+(const float vec[2]) {
            return vec2(x + vec[0], y + vec[1]);
        }

        vec2 operator+(const float value) {
            return vec2(x + value, y + value);
        }

        vec2 operator-(const vec2 vec) {
            return vec2(x - vec.x, y - vec.y);
        }

        vec2 operator-(const float vec[2]) {
            return vec2(x - vec[0], y - vec[1]);
        }

        vec2 operator-(const float value) {
            return vec2(x - value, y - value);
        }

        vec2 operator-() {
            return vec2(-x, -y);
        }

        vec2 operator*(const vec2 vec) {
            return vec2(x * vec.x, y * vec.y);
        }

        vec2 operator*(const float vec[2]) {
            return vec2(x * vec[0], y * vec[1]);
        }

        vec2 operator*(const float value) {
            return vec2(x * value, y * value);
        }

        vec2 operator/(const vec2 vec) {
            return vec2(x / vec.x, y / vec.y);
        }

        vec2 operator/(const float vec[2]) {
            return vec2(x / vec[0], y / vec[1]);
        }

        vec2 operator/(const float value) {
            return vec2(x / value, y / value);
        }

        void operator+=(const vec2 vec) {
            x += vec.x, y += vec.y;
        }

        void operator+=(const float vec[2]) {
            x += vec[0], y += vec[1];
        }

        void operator+=(const float value) {
            x += value, y += value;
        }

        void operator-=(const vec2 vec) {
            x -= vec.x, y -= vec.y;
        }

        void operator-=(const float vec[2]) {
            x -= vec[0], y -= vec[1];
        }

        void operator-=(const float value) {
            x -= value, y -= value;
        }

        void operator*=(const vec2 vec) {
            x *= vec.x, y *= vec.y;
        }

        void operator*=(const float vec[2]) {
            x *= vec[0], y *= vec[1];
        }

        void operator*=(const float value) {
            x *= value, y *= value;
        }

        void operator/=(const vec2 vec) {
            x /= vec.x, y /= vec.y;
        }

        void operator/=(const float vec[2]) {
            x /= vec[0], y /= vec[1];
        }

        void operator/=(const float value) {
            x /= value, y /= value;
        }

        bool operator==(const vec2 vec) {
            return x == vec.x && y == vec.y;
        }

        bool operator==(const float vec[2]) {
            return x == vec[0] && y == vec[1];
        }

        bool operator==(const float value) {
            return x == value && y == value;
        }

        bool operator!=(const vec2 vec) {
            return x != vec.x || y != vec.y;
        }

        bool operator!=(const float vec[2]) {
            return x != vec[0] || y != vec[1];
        }

        bool operator!=(const float value) {
            return x != value || y != value;
        }

        float& operator[](const int i) {
            return v[i];
        }

        operator float*() {
            return (float*)&this[0];
        }

        operator const float*() {
            return (const float*)&this[0];
        }

        float magnitude() {
            return vsh::sqrtf(dot(*this));
        }

        float dot(vec2 vec) {
            return (x * vec.x) + (y * vec.y);
        }

        float distance(vec2 vec) {
            vec2 diff = *this - vec;
            return diff.magnitude();
        }

        vec2& normalize() {
            *this /= magnitude();
            return *this;
        }

        vec2& negate() {
            *this = -*this;
            return *this;
        }

        vec2& clamp(float min, float max) {
            x = (x > max) ? max : (x < min) ? min : x;
            y = (y > max) ? max : (y < min) ? min : y;
            return *this;
        }
    };

    class vec3
    {
    public:
        union {
            float v[3];
            struct { float x, y, z; };
            struct { float pitch, yaw, roll; };
        };

        vec3()
            : x(0), y(0), z(0) {}

        vec3(float x, float y, float z)
            : x(x), y(y), z(z) {}

        vec3(float vec[3]) {
            if (vec)
                x = vec[0], y = vec[1], z = vec[2];
            else
                *this = vec3();
        }

        vec3 operator+(const vec3 vec) {
            return vec3(x + vec.x, y + vec.y, z + vec.z);
        }

        vec3 operator+(const float vec[3]) {
            return vec3(x + vec[0], y + vec[1], z + vec[2]);
        }

        vec3 operator+(const float value) {
            return vec3(x + value, y + value, z + value);
        }

        vec3 operator-(const vec3 vec) {
            return vec3(x - vec.x, y - vec.y, z - vec.z);
        }

        vec3 operator-(const float vec[3]) {
            return vec3(x - vec[0], y - vec[1], z - vec[2]);
        }

        vec3 operator-(const float value) {
            return vec3(x - value, y - value, z - value);
        }

        vec3 operator-() {
            return vec3(-x, -y, -z);
        }

        vec3 operator*(const vec3 vec) {
            return vec3(x * vec.x, y * vec.y, z * vec.z);
        }

        vec3 operator*(const float vec[3]) {
            return vec3(x * vec[0], y * vec[1], z * vec[2]);
        }

        vec3 operator*(const float value) {
            return vec3(x * value, y * value, z * value);
        }

        vec3 operator/(const vec3 vec) {
            return vec3(x / vec.x, y / vec.y, z / vec.z);
        }

        vec3 operator/(const float vec[3]) {
            return vec3(x / vec[0], y / vec[1], z / vec[2]);
        }

        vec3 operator/(const float value) {
            return vec3(x / value, y / value, z / value);
        }

        void operator+=(const vec3 vec) {
            x += vec.x, y += vec.y, z += vec.z;
        }

        void operator+=(const float vec[3]) {
            x += vec[0], y += vec[1], z += vec[2];
        }

        void operator+=(const float value) {
            x += value, y += value, z += value;
        }

        void operator-=(const vec3 vec) {
            x -= vec.x, y -= vec.y, z -= vec.z;
        }

        void operator-=(const float vec[3]) {
            x -= vec[0], y -= vec[1], z -= vec[2];
        }

        void operator-=(const float value) {
            x -= value, y -= value, z -= value;
        }

        void operator*=(const vec3 vec) {
            x *= vec.x, y *= vec.y, z *= vec.z;
        }

        void operator*=(const float vec[3]) {
            x *= vec[0], y *= vec[1], z *= vec[2];
        }

        void operator*=(const float value) {
            x *= value, y *= value, z *= value;
        }

        void operator/=(const vec3 vec) {
            x /= vec.x, y /= vec.y, z /= vec.z;
        }

        void operator/=(const float vec[3]) {
            x /= vec[0], y /= vec[1], z /= vec[2];
        }

        void operator/=(const float value) {
            x /= value, y /= value, z /= value;
        }

        bool operator==(const vec3 vec) {
            return x == vec.x && y == vec.y && z == vec.z;
        }

        bool operator==(const float vec[3]) {
            return x == vec[0] && y == vec[1] && z == vec[2];
        }

        bool operator==(const float value) {
            return x == value && y == value && z == value;
        }

        bool operator!=(const vec3 vec) {
            return x != vec.x || y != vec.y || z != vec.z;
        }

        bool operator!=(const float vec[3]) {
            return x != vec[0] || y != vec[1] || z != vec[2];
        }

        bool operator!=(const float value) {
            return x != value || y != value || z != value;
        }

        float& operator[](const int i) {
            return v[i];
        }

        operator float*() {
            return (float*)&this[0];
        }

        operator const float*() {
            return (const float*)&this[0];
        }

        float magnitude() {
            return vsh::sqrtf(dot(*this));
        }

        float dot(vec3 vec) {
            return (x * vec.x) + (y * vec.y) + (z * vec.z);
        }

        float distance(vec3 vec) {
            vec3 diff = *this - vec;
            return diff.magnitude();
        }

        vec3& normalize() {
            *this /= magnitude();
            return *this;
        }

        vec3& negate() {
            *this = -*this;
            return *this;
        }

        vec3& clamp(float min, float max) {
            x = (x > max) ? max : (x < min) ? min : x;
            y = (y > max) ? max : (y < min) ? min : y;
            z = (z > max) ? max : (z < min) ? min : z;
            return *this;
        }
    };

    class vec4
    {
    public:
        union {
            float v[4];
            struct { float x, y, z, w; };
            struct { float r, g, b, a; };
            struct { float pitch, yaw, roll; };
        };

        vec4()
            : x(0), y(0), z(0), w(0) {}

        vec4(float x, float y, float z, float w)
            : x(x), y(y), z(z), w(w) {}

        vec4(float vec[4]) {
            if (vec)
                x = vec[0], y = vec[1], z = vec[2], w = vec[3];
            else
                *this = vec4();
        }

        vec4 operator+(const vec4 vec) {
            return vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
        }

        vec4 operator+(const float vec[4]) {
            return vec4(x + vec[0], y + vec[1], z + vec[2], w + vec[3]);
        }

        vec4 operator+(const float value) {
            return vec4(x + value, y + value, z + value, w + value);
        }

        vec4 operator-(const vec4 vec) {
            return vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
        }

        vec4 operator-(const float vec[4]) {
            return vec4(x - vec[0], y - vec[1], z - vec[2], w - vec[3]);
        }

        vec4 operator-(const float value) {
            return vec4(x - value, y - value, z - value, w - value);
        }

        vec4 operator-() {
            return vec4(-x, -y, -z, -w);
        }

        vec4 operator*(const vec4 vec) {
            return vec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
        }

        vec4 operator*(const float vec[4]) {
            return vec4(x * vec[0], y * vec[1], z * vec[2], w * vec[3]);
        }

        vec4 operator*(const float value) {
            return vec4(x * value, y * value, z * value, w * value);
        }

        vec4 operator/(const vec4 vec) {
            return vec4(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
        }

        vec4 operator/(const float vec[4]) {
            return vec4(x / vec[0], y / vec[1], z / vec[2], w / vec[3]);
        }

        vec4 operator/(const float value) {
            return vec4(x / value, y / value, z / value, w / value);
        }

        void operator+=(const vec4 vec) {
            x += vec.x, y += vec.y, z += vec.z, w += vec.w;
        }

        void operator+=(const float vec[4]) {
            x += vec[0], y += vec[1], z += vec[2], w += vec[3];
        }

        void operator+=(const float value) {
            x += value, y += value, z += value, w += value;
        }

        void operator-=(const vec4 vec) {
            x -= vec.x, y -= vec.y, z -= vec.z, w -= vec.w;
        }

        void operator-=(const float vec[4]) {
            x -= vec[0], y -= vec[1], z -= vec[2], w -= vec[3];
        }

        void operator-=(const float value) {
            x -= value, y -= value, z -= value, w -= value;
        }

        void operator*=(const vec4 vec) {
            x *= vec.x, y *= vec.y, z *= vec.z, w *= vec.w;
        }

        void operator*=(const float vec[4]) {
            x *= vec[0], y *= vec[1], z *= vec[2], w *= vec[3];
        }

        void operator*=(const float value) {
            x *= value, y *= value, z *= value, w *= value;
        }

        void operator/=(const vec4 vec) {
            x /= vec.x, y /= vec.y, z /= vec.z, w /= vec.w;
        }

        void operator/=(const float vec[4]) {
            x /= vec[0], y /= vec[1], z /= vec[2], w /= vec[3];
        }

        void operator/=(const float value) {
            x /= value, y /= value, z /= value, w /= value;
        }

        bool operator==(const vec4 vec) {
            return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
        }

        bool operator==(const float vec[4]) {
            return x == vec[0] && y == vec[1] && z == vec[2] && w == vec[3];
        }

        bool operator==(const float value) {
            return x == value && y == value && z == value && w == value;
        }

        bool operator!=(const vec4 vec) {
            return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
        }

        bool operator!=(const float vec[4]) {
            return x != vec[0] || y != vec[1] || z != vec[2] || w != vec[3];
        }

        bool operator!=(const float value) {
            return x != value || y != value || z != value || w != value;
        }

        float& operator[](const int i) {
            return v[i];
        }

        operator float*() {
            return (float*)&this[0];
        }

        operator const float*() {
            return (const float*)&this[0];
        }

        float magnitude() {
            return vsh::sqrtf(dot(*this));
        }

        float dot(vec4 vec) {
            return (x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w);
        }

        float distance(vec4 vec) {
            vec4 diff = *this - vec;
            return diff.magnitude();
        }

        vec4& normalize() {
            *this /= magnitude();
            return *this;
        }

        vec4& negate() {
            *this = -*this;
            return *this;
        }

        vec4& clamp(float min, float max) {
            x = (x > max) ? max : (x < min) ? min : x;
            y = (y > max) ? max : (y < min) ? min : y;
            z = (z > max) ? max : (z < min) ? min : z;
            w = (w > max) ? max : (w < min) ? min : w;
            return *this;
        }
    };

    class mat4
    {
    public:
        mat4() = default;

        mat4(mat4 const& mat) {
            for (int row = 0; row < 4; row++)
                for (int col = 0; col < 4; col++)
                    _Entries[row][col] = mat[row][col];
        }

        float* operator [] (int Row) {
            return _Entries[Row];
        }
        const float* operator [] (int Row) const {
            return _Entries[Row];
        }

    public:
        float _Entries[4][4]; // rows/cols
    };

    // forward declarations
    class Thread;
    class Framework;

    class Surface;
    template<class _Ty> class SurfaceRCPtr;
    using SurfacePtr = SurfaceRCPtr<Surface>;

    class View;
    class Module;

    class PhSText;
    class PhSRender;
    class PhEvent;
    class PhHandler;
    class PhWidget;
    class PhPlane;
    class PhText;

    CDECL_BEGIN

        // paf_50239384 // File_AllocLoad // 
        // paf_6B9B2829 // File_GetSize // 
        // paf_70DADB9D // File_Load // 
        // paf_9DB8660C // File_Save // 
        // paf_72292B61 // InputDevice_DisableAnalog // 
        // paf_FC58CA65 // InputDevice_EnableAnalog // 
        // paf_855C13DC // InputDevice_EnableAnalogThreshold // 
        // paf_32658F00 // InputDevice_Get // 
        // paf_3BC69C3A // InputDevice_GetKeyAssign // 
        // paf_3FAD4311 // InputDevice_GetOwnership // 
        // paf_55944323 // InputDevice_IsOwner // 
        // paf_55EE69A7 // InputDevice_Lock // 
        // paf_DAFE04B9 // InputDevice_Ps3Pad_EnableAnalog // 
        // paf_9C8D34DC // InputDevice_Ps3Pad_SetFilterHandler // 
        // paf_FA17FC05 // InputDevice_ReleaseOwnership // 
        // paf_0F0A07EA // InputDevice_SetKeyAssign // 
        // paf_18B76C7D // InputDevice_SetModifierKey // 
        void paf_E26BBDE4(); // InputDevice_Unlock // 
    // paf_5264AC5C // PAF_Resource_DOMGetNodeChildByID // 
    // paf_20BA8E1A // PAF_Resource_DOMGetNodeChildByPos // 
    // paf_718C9629 // PAF_Resource_DOMGetNodeData // 
    // paf_08598228 // PAF_Resource_DOMGetNodeFirstChild // 
    // paf_6997E44A // PAF_Resource_DOMGetNodeID // 
    // paf_3FEF8AC9 // PAF_Resource_DOMGetNodeNext // 
    // paf_8B9AAD3E // PAF_Resource_DOMGetNodeType // 
    // paf_19A0F619 // PAF_Resource_GetPageNodeByID // 
    // paf_01D59A4E // PAF_Resource_GetWidgetNodeByID // 
    // paf_76AD182B // PAF_Resource_ResolveRefNode // 
    // paf_8644EEA8 // PAF_Resource_ResolveRefString // 
    // paf_EFC45C20 // PAF_Resource_ResolveRefWString // 
    // paf_B2EC23EB // PhiChangeResource // 
    // paf_40410F89 // PhiGetDisplay // 
    // paf_385FAD55 // PhiPostKeycodeEvent // 
    // paf_56760422 // PhiPostSystemEvent // 
    // paf_97B18ECE // PhiRegistResultDisplayCB // 
    // paf_D7138829 // PhiSetLayoutTable // 
    // paf_04C19A94 // PhiUpdateDisplay // 
    // paf_D8AF2727 // PhiUpdateDisplay_platform // 
    // paf_526C2374 // Platform_GetConfig // 

    // paf_14A9CC1D // _ZN4mat4C1Ef					// mat4::mat4(float)
    // paf_964CE2DD // _ZN4mat4C1Effffffffffffffff	// mat4::mat4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
    // paf_BC6E66D6 // _ZN4mat4aSEf					// mat4::operator=(float)
    // paf_EE8F2CC4 // _ZN4mat4ixEi					// mat4::operator[](int)
    // paf_4F2A97E5 // _ZN4rectC1Ef					// rect::rect(float)
    // paf_FADF8AFF // _ZN4rectC1Effff				// rect::rect(float, float, float, float)
    // paf_A922709B // _ZN4rectaSEf					// rect::operator=(float)
    // paf_18320785 // _ZN4vec23setEff				// vec2::set(float, float)
    // paf_84484D13 // _ZN4vec2C1Ef					// vec2::vec2(float)
    // paf_B1A2076D // _ZN4vec2aSERK4vec4			// vec2::operator=(vec4 const&)
    // paf_DF27BD9B // _ZN4vec3C1Efff				// vec3::vec3(float, float, float)
    // paf_D72BCDCB // _ZN4vec4C1ERK4vec2			// vec4::vec4(vec2 const&)
    // paf_0D84691B // _ZN4vec4C1Ef					// vec4::vec4(float)
    // paf_4BCD3A77 // _ZN4vec4C1Efff				// vec4::vec4(float, float, float)
    // paf_C44F501D // _ZN4vec4aSEf					// vec4::operator=(float)
    // paf_585EC026 // _ZN4vec4ixEi					// vec4::operator[](int)
    // paf_9EB7F788 // _ZNK4vec4eqERKS_				// vec4::operator==(vec4 const&)const
    // paf_CA16B292 // _ZmLR4mat4RKS_				// operator*=(mat4 &, mat4 const&)
    // paf_023F6755 // _ZmLR4vec4RKS_				// operator*=(vec4 &, vec4 const&)
    // paf_87D90A81 // _ZmiRK4vec4S1_				// operator-(vec4 const&, vec4 const&)
    // paf_DA6B5FAD // _ZmlRK4mat4RK4vec4			// operator*(mat4 const&, vec4 const&)
    // paf_DC05D196 // _ZmlRK4mat4S1_				// operator*(mat4 const&, mat4 const&)
    // paf_151D5C78 // _ZmlRK4vec4S1_				// operator*(vec4 const&, vec4 const&)
    // paf_4F381F53 // _ZmlRK4vec4f					// operator*(vec4 const&, float)
    // paf_724042E6 // _ZpLR4vec4RKS_				// operator+=(vec4 &, vec4 const&)
    // paf_AABDBC6E // _ZplRK4vec4S1_				// operator+(vec4 const&, vec4 const&)

    // paf_E0A3AA72 // _Z10normalize3RK4vec4		// normalize3(vec4 const&)
    // paf_1167D7F4 // _Z15mat4_from_scaleRK4vec4	// mat4_from_scale(vec4 const&)
    // paf_4C229CCA // _Z16mat4_from_rotyxzfff		// mat4_from_rotyxz(float, float, float)
    // paf_D774E03E // _Z19mat4_from_translatefff	// mat4_from_translate(float, float, float)
    // paf_A337B314 // _Z5lerp2RK4vec4S1_f			// lerp2(vec4 const&, vec4 const&, float)
    // paf_1738DDE3 // _Z5lerp3RK4vec4S1_f			// lerp3(vec4 const&, vec4 const&, float)
    // paf_3D841FE9 // _Z5lerp4RK4vec4S1_f			// lerp4(vec4 const&, vec4 const&, float)
    // paf_FD846612 // _Z6clamp4RK4vec4ff			// clamp4(vec4 const&, float, float)
    // paf_5232FAAF // _Z7inverseRK4mat4			// inverse(mat4 const&)
    // paf_3CAE2F8A // _Z9normalizeRK4mat4			// normalize(mat4 const&)
    // paf_EFC3730F // _Z9transposeRK4mat4			// transpose(mat4 const&)

    // paf_5E671849 // _Z11pafGumScalePK4vec3		// pafGumScale(vec3 const*)
    // paf_959BF279 // _Z15pafGumDrawArrayiiiPKvS0_ // pafGumDrawArray(int, int, int, void const*, void const*)
    // paf_654B91B5 // _Z15pafGumPopMatrixv			// pafGumPopMatrix(void)
    // paf_87BBE314 // _Z15pafGumTranslatePK4vec3	// pafGumTranslate(vec3 const*)
    // paf_5919DAD3 // _Z16pafGumLoadMatrixPK4mat4	// pafGumLoadMatrix(mat4 const*)
    // paf_8E7A2AED // _Z16pafGumMatrixModei		// pafGumMatrixMode(int)
    // paf_B4D3C063 // _Z16pafGumPushMatrixv		// pafGumPushMatrix(void)
    // paf_88DDE2F3 // _Z17pafGumStoreMatrixP4mat4	// pafGumStoreMatrix(mat4 *)
    // paf_5F096D38 // _Z18pafGumLoadIdentityv		// pafGumLoadIdentity(void)
    // paf_1EFB3790 // pafGuBlendFunc
    // paf_399C0BF0 // pafGuCgCreateFragmentShader
    // paf_A65A3868 // pafGuCgCreateShader
    // paf_CA103173 // pafGuCgCreateVertexShader
    // paf_8FEC308A // pafGuCgPopShader
    // paf_64C305D6 // pafGuCgPushShader
    // paf_97BD8488 // pafGuCgReleaseFragmentShader
    // paf_B1D5806A // pafGuCgReleaseVertexShader
    // paf_6B7D0D60 // pafGuCgSetFragmentShader
    // paf_E921EAA5 // pafGuCgSetShader
    // paf_D61B5EFC // pafGuCgSetVertexShader
    // paf_20E5286E // pafGuClear
    // paf_84D5E999 // pafGuClearColor
    // paf_19731532 // pafGuClearDepth
    // paf_ADD67C35 // pafGuColor4f
    // paf_BD1BF0B7 // pafGuDataLocation
    // paf_3F2FD49C // pafGuDepthBuffer
    // paf_9F3D573E // pafGuDepthFunc
    // paf_E4FE1333 // pafGuDepthMask
    // paf_E93B9B31 // pafGuDisable
    // paf_41C145DC // pafGuDrawArray
    // paf_39B40DF9 // pafGuDrawBuffer
    // paf_CA1E9947 // pafGuEnable
    int paf_F00CAD11(); // pafGuFrameCount
    static int GetFrameCount() { return paf_F00CAD11(); }
    // paf_2C519D3B // pafGuFrontFace
    // paf_A0FCDF5F // pafGuGetCurrDisplayDeviceSurf
    // paf_7D45A4FF // pafGuGetCurrVirtualScreenSurf
    // paf_076402CA // pafGuGetDisplayMode
    int paf_AC984A12(); // pafGuGetDrawSurfH
    static float GetScreenHeight() { return static_cast<float>(paf_AC984A12()); }
    int paf_F476E8AA(); // pafGuGetDrawSurfW
    static float GetScreenWidth() { return static_cast<float>(paf_F476E8AA()); }
    // paf_0FFACD6D // pafGuGetVideoMemoryTotalArea
    // paf_98F14FD9 // pafGuGetVirtualScreenSurf
    // paf_2E34FF61 // pafGuMuteDisplay
    // paf_124DDBC5 // pafGuRefreshStatus
    // paf_3C7E4CE0 // pafGuScissor
    // paf_9C1A2D6A // pafGuSetDrawSurfH
    // paf_A01698C9 // pafGuSetDrawSurfW
    // paf_D6AEAC39 // pafGuShadeModel
    // paf_4B9B85B4 // pafGuSwapCount
    // paf_036D6368 // pafGuSwapStatus
    // paf_2164ACB8 // pafGuSyncGpu
    // paf_3B90102F // pafGuSyncGpuAll
    // paf_C8F4E2CF // pafGuTexFilter
    // paf_62854AA7 // pafGuTexImage
    // paf_344E1CEB // pafGuTexImage2
    // paf_00C147B2 // pafGuTexLevelMode
    // paf_6001C52A // pafGuTexMode
    // paf_BB0AA6D5 // pafGuTexOffset
    // paf_2D6B25EA // pafGuTexScale
    // paf_6941C365 // pafGuTexWrap
    // paf_191AD326 // pafGuViewport

    // paf_4DED0C42 // sceWaveAudioGetRestSample
    // paf_467B2193 // sceWaveAudioSetFormat
    // paf_F75DD0B5 // sceWaveAudioSetSample
    // paf_483CBA61 // sceWaveAudioSetVolumeEx
    // paf_C5EC06C5 // sceWaveAudioWriteBlockingEx

    // paf_55F2C2A6 // eject disc
    // paf_BB04609B // GetSparkInfo
    // paf_65BE85B3 // _UnloadView(char * plugin_name, 0, 0)

    // paf_EAD0EFAC // _ZN3Ime21OskCreateInputContextEPNS_17ImeOskCreateParamE			// Ime::OskCreateInputContext(Ime::ImeOskCreateParam *)
    // paf_FEAD5829 // _ZN3Ime21RegisterPanelCallbackEPNS_20OskpanelCallbackListE		// Ime::RegisterPanelCallback(Ime::OskpanelCallbackList *)
    // paf_F66AAF4B // _ZN3Ime22OskReleaseInputContextEPNS_21InputContextInterfaceE		// Ime::OskReleaseInputContext(Ime::InputContextInterface *)

    int paf_9C1D60C4(Thread const* thread); // paf::Thread::Join(void)
    int paf_97D7BF2A(Thread const* thread); // paf::Thread::Start(void)
    void paf_DFE8806F(Thread const* thread, int, unsigned int, char const*, unsigned int); // paf::Thread::Thread(int, unsigned int, char const*, unsigned int)
    void paf_EBD30F24(Thread const* thread); // paf::Thread::~Thread()

    // paf_45F7D5ED // _ZN3paf15CriticalSection5EnterEv		// paf::CriticalSection::Enter(void)
    // paf_5C6C78E5 // _ZN3paf15CriticalSection5LeaveEv		// paf::CriticalSection::Leave(void)
    // paf_E9A06D0A // _ZN3paf15CriticalSectionC1Ev			// paf::CriticalSection::CriticalSection(void)
    // paf_DE9C6F25 // _ZN3paf15CriticalSectionD1Ev			// paf::CriticalSection::~CriticalSection()

    // paf_ED058E54 // _ZN3paf4Cond4WaitEv					// paf::Cond::Wait(void)
    // paf_75D9466C // _ZN3paf4Cond6NotifyEv				// paf::Cond::Notify(void)
    // paf_DFE2B134 // _ZN3paf4Cond9NotifyAllEv				// paf::Cond::NotifyAll(void)
    // paf_AA422FCB // _ZN3paf4CondC1ERNS_5MutexEPKc		// paf::Cond::Cond(paf::Mutex &, char const*)
    // paf_8D81B2F3 // _ZN3paf4CondD1Ev						// paf::Cond::~Cond()

    // paf_89E5CC7F // _ZN3paf8SyncCall4CallEPFiPvES1_		// paf::SyncCall::Call(int(*)(void *), void *)
    // paf_EB7D2C26 // _ZN3paf8SyncCall5CheckEv				// paf::SyncCall::Check(void)
    // paf_1CCF9E4D // _ZN3paf8SyncCallC1Ev					// paf::SyncCall::SyncCall(void)
    // paf_CC9C89FB // _ZN3paf8SyncCallD1Ev					// paf::SyncCall::~SyncCall()

    // paf_CFF699A0 // _ZN3paf9CallQueue4PostEPFvPvES1_												// paf::CallQueue::Post(void(*)(void *), void *)
    // paf_9F58ADCF // _ZN3paf9CallQueue5CheckEv													// paf::CallQueue::Check(void)
    // paf_350B4536 // _ZN3paf9Job_StartEPNS_9Job_QueueEPFiPvPNS_10Job_ThreadEES2_iiPFviS2_S4_iE	// paf::Job_Start(paf::Job_Queue *, int(*)(void *, paf::Job_Thread *), void *, int, int, void(*)(int, void *, paf::Job_Thread *, int))
    // paf_5D836E75 // _ZN3paf10Job_CancelEPNS_9Job_QueueEPNS_10Job_ThreadEi						// paf::Job_Cancel(paf::Job_Queue *, paf::Job_Thread *, int)
    // paf_33944117 // _ZN3paf14Job_isCanceledEPNS_10Job_ThreadE									// paf::Job_isCanceled(paf::Job_Thread *)
    // paf_FE0C1F10 // _ZN3paf15Job_CreateQueueEv													// paf::Job_CreateQueue(void)
    // paf_D385A4FC // _ZN3paf16Job_DestroyQueueEPNS_9Job_QueueE									// paf::Job_DestroyQueue(paf::Job_Queue *)
    // paf_AC90BC8F // _ZN3paf18Job_GetNumOfThreadEPNS_9Job_QueueE									// paf::Job_GetNumOfThread(paf::Job_Queue *)

    void paf_AD9051B6(int millis); // paf::Sleep(int)
    static void Sleep(int millis) { paf_AD9051B6(millis); }

    // paf_64527FA9 // _ZN3paf10DecompressEPvjPKvj																						// paf::Decompress(void *, unsigned int, void const*, unsigned int)
    // paf_73878BBE // _ZN3paf11SplitStringEPSt6vectorISsSaISsEERKSsS5_j																// paf::SplitString(std::vector<std::string, std::allocator<std::string> > *, std::string const&, std::string const&, unsigned int)
    // paf_BE04476B // _ZN3paf10PhDrawTextENS_6PhFont9GlyphTypeERNS_12SurfaceRCPtrINS_7SurfaceEEEiiPKwjRKS0_PKNS_17PhTextLetterSpaceE	// paf::PhDrawText(paf::PhFont::GlyphType, paf::SurfaceRCPtr<paf::Surface> &, int, int, wchar_t const*, unsigned int, paf::PhFont const&, paf::PhTextLetterSpace const*)
    // paf_689DCA1F // _ZN3paf14PhGetTextWidthENS_6PhFont9GlyphTypeERKSbIwSt11char_traitsIwESaIwEEjjRKS0_PKNS_17PhTextLetterSpaceE		// paf::PhGetTextWidth(paf::PhFont::GlyphType, std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >  const&, unsigned int, unsigned int, paf::PhFont const&, paf::PhTextLetterSpace const*)
    // paf_6E6A92EB // _ZN3paf23SetFormatStringCallbackEPFPKwwE																			// paf::SetFormatStringCallback(wchar_t const* (*)(wchar_t))

    // paf_C0F6890C // _ZN3paf13AVCopyControl10SetWSSCodeEjj	// paf::AVCopyControl::SetWSSCode(unsigned int, unsigned int)
    // paf_4B00C738 // _ZN3paf13AVCopyControl11SetVBIDCodeEjj	// paf::AVCopyControl::SetVBIDCode(unsigned int, unsigned int)
    // paf_22C482F2 // _ZN3paf13AVCopyControlC1Ev				// paf::AVCopyControl::AVCopyControl(void)

    // paf_28E3DF10 // _ZN3paf14GraphicsMemory3MapEPvj										// paf::GraphicsMemory::Map(void *, unsigned int)
    // paf_4922A06A // _ZN3paf14GraphicsMemory4Area13AllocFromHeapENS0_10DeviceTypeEijj		// paf::GraphicsMemory::Area::AllocFromHeap(paf::GraphicsMemory::DeviceType, int, unsigned int, unsigned int)
    // paf_AA1A8C53 // _ZN3paf14GraphicsMemory4Area13AllocFromPoolENS0_10DeviceTypeEijPj	// paf::GraphicsMemory::Area::AllocFromPool(paf::GraphicsMemory::DeviceType, int, unsigned int, unsigned int *)
    // paf_9BA36D14 // _ZN3paf14GraphicsMemory4Area4FreeEPv									// paf::GraphicsMemory::Area::Free(void *)

    void* paf_B9152E15(Module const* module, int interfaceId); // paf::Module::GetInterface(int)const
    void paf_3F7CB0BF(Module const* module, int interfaceId, void* interfaceStruct); // paf::Module::SetInterface(int, void *)
    void paf_CF068D31(Module const* module, char const* path, int unused, int unknownParam, sys_memory_container_t* memContainer); // paf::Module::Module(char const*, int, int, sys_memory_container_t *) ? not sure, r5 is unused and r6 is stored at 0x30 in da module struct
    void paf_2F5CEE6D(Module const* module); // paf::Module::~Module()

    // paf_7EE103EF // _ZN3paf4View12PageActivateEPKc								// paf::View::PageActivate(char const*)
    // paf_2166E819 // _ZN3paf4View12PageActivateEPv								// paf::View::PageActivate(void *)
    void paf_202CA2A7(View const* view); // paf::View::PageCloseAll(void)
    void paf_0A1DC401(View const* view, int interfaceId, void* interfaceStruct); // paf::View::SetInterface(int, void *)
    // paf_E50657B1 // _ZN3paf4View12SetLocaleAllE6Locale							// paf::View::SetLocaleAll(Locale)
    // paf_E014D3BA // _ZN3paf4View12StopSoundAllEv									// paf::View::StopSoundAll(void)
    void paf_2F58C5DF(View const* view, char const* page); // paf::View::PageInactivate(char const*)
    // paf_DF5E3BFD // _ZN3paf4View15SetDrawPriorityEi								// paf::View::SetDrawPriority(int)
    // paf_9DB21A04 // _ZN3paf4View15SetEventHandlerEPKNS_18EventFunctionEntryE		// paf::View::SetEventHandler(paf::EventFunctionEntry const*)
    // paf_8BC523EB // _ZN3paf4View16PlayAnimSequenceEPNS_8PhWidgetEPKc				// paf::View::PlayAnimSequence(paf::PhWidget *, char const*)
    View* paf_F21655F3(char const* name); // paf::View::Find(char const*)
    // paf_92F7E387 // _ZN3paf4View8ActivateEv										// paf::View::Activate(void)
    // paf_50CDB465 // _ZN3paf4View8GetSoundEPKc									// paf::View::GetSound(char const*)
    // paf_2C4E7D1C // _ZN3paf4View9InitParamC1Ev									// paf::View::InitParam::InitParam(void)
    int paf_724E5A8B(View const* view, char const* page); // paf::View::PageClose(char const*)
    // paf_75457863 // _ZN3paf4View9PageCloseEPv									// paf::View::PageClose(void *)
    // paf_91404635 // _ZN3paf4View9SetLocaleE6Locale								// paf::View::SetLocale(Locale)
    PhWidget* paf_794CEACB(View const* view, char const* widget); // paf::View::FindWidget(char const*)const
    SurfacePtr& paf_3A8454FC(SurfacePtr& handle, View const* view, char const* texture);  // paf::View::GetTexture(char const*)const
    // paf_A499E2BE // _ZNK3paf4View10GetTextureEPv									// paf::View::GetTexture(void *)const
    // paf_42B2CD4A // _ZNK3paf4View10GetTopPageEv									// paf::View::GetTopPage(void)const
    void* paf_23AFB290(View const* view, int interfaceId); // paf::View::GetInterface(int)const
    void paf_430FCFED(View const* view, int r4); // paf::View::Notify(int)const
    // paf_46D0F875 // _ZNK3paf4View7GetPageEPKc									// paf::View::GetPage(char const*)const
    // paf_F5BEB953 // _ZNK3paf4View8ArgumentcvSsEv									// paf::View::Argument::operator std::string(void)const
    // paf_E5B6AF9E // _ZNK3paf4View8ArgumentcviEv									// paf::View::Argument::operator int(void)const
    // paf_99919819 // _ZNK3paf4View8IsActiveEv										// paf::View::IsActive(void)const
    // paf_11E195B3 // _ZNK3paf4View8PageRootEPKc									// paf::View::PageRoot(char const*)const
    // paf_BCAACE40 // _ZNK3paf4View8PageRootEPv									// paf::View::PageRoot(void *)const
    wchar_t* paf_89B67B9C(View const* view, char const* localizedString); // paf::View::GetString(char const*)const
    void paf_B93AFE7E(View const* view, char const* systemSound, float f1, int r6); // paf::View::PlaySound ?

    // paf_873C6688 // _ZN3paf7PhTimer12GetFrameTimeEv	// paf::PhTimer::GetFrameTime(void)
    // paf_2E5D1BB3 // _ZNK3paf7PhTimer6DoFuncEfi		// paf::PhTimer::DoFunc(float, int)const

    // paf_C11E4924 // _ZN3paf13PhApplication13GetRootScreenEv					// paf::PhApplication::GetRootScreen(void)
    // paf_EA225A69 // _ZN3paf13PhApplication15CalcLayoutValueEiiiRK4vec4		// paf::PhApplication::CalcLayoutValue(int, int, int, vec4 const&)
    // paf_CCE0FADA // _ZN3paf13PhApplication15SetCustomRenderEPFvPS0_E			// paf::PhApplication::SetCustomRender(void(*)(paf::PhApplication*))
    // paf_530D8265 // _ZN3paf13PhApplication21DeleteUpdateDisplayCBEPFiiiiE	// paf::PhApplication::DeleteUpdateDisplayCB(int(*)(int, int, int))
    // paf_7902DF28 // _ZN3paf13PhApplication21RegistUpdateDisplayCBEPFiiiiE	// paf::PhApplication::RegistUpdateDisplayCB(int(*)(int, int, int))
    // paf_1ED44FDD // _ZN3paf13PhApplication9PostEventEPNS_7PhEventE			// paf::PhApplication::PostEvent(paf::PhEvent *)

    int paf_1565FC46(Framework const* framework); // paf::Framework::RequestShutdown()
    // paf_ED7791B6 // _ZN3paf9Framework16GetSoundInstanceEv			// paf::Framework::GetSoundInstance(void)
    int paf_59BDA198(Framework const* framework, float frameTime); // paf::Framework::Begin(float)
    int paf_85D1D23B(Framework const* framework, float frameTime); // paf::Framework::Run(float)
    int paf_0EAA28B8(Framework const* framework, float frameTime); // paf::Framework::End(float)
    Framework& paf_AF58E756(); // paf::Framework::Instance(void)
    void paf_541F8EBB(void* initParam); // paf::Framework::InitParam::InitParam(void)
    void paf_A5B4FB55(Framework const* framework, void* initParam); // paf::Framework::Framework(paf::Framework::InitParam const&)
    void paf_54E2C229(Framework const* framework); // paf::Framework::~Framework()

    // PhCamera class size: 0x3EC ?        imagine making an xmb noclip  lmao could be dope
    // paf_647CB8EF // _ZN3paf8PhCamera12UpdateParamsEv					// paf::PhCamera::UpdateParams(void)
    // paf_7415A11D // _ZN3paf8PhCamera16SetVirtualScreenEfff			// paf::PhCamera::SetVirtualScreen(float, float, float)
    // paf_BAFE871A // _ZN3paf8PhCamera26SetVirtualScreenAdjustDistEff	// paf::PhCamera::SetVirtualScreenAdjustDist(float, float)
    // paf_9D014B62 // _ZN3paf8PhCamera5SetupEv							// paf::PhCamera::Setup(void)
    // paf_F87ADBD7 // _ZN3paf8PhCameraC1EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhCamera::PhCamera(paf::PhWidget *, paf::PhAppear *)
    // paf_7A200FA1 // _ZNK3paf8PhCamera16GetVirtualScreenERfS1_S1_		// paf::PhCamera::GetVirtualScreen(float &, float &, float &)const

    // aight but how do we find da scene
    // paf_41BBFE5E // _ZN3paf7PhScene10WidgetTypeEv					// paf::PhScene::WidgetType(void)
    // paf_168EA34B // _ZNK3paf7PhScene14GetCameraCountEv				// paf::PhScene::GetCameraCount(void)const
    // paf_C47FB4B9 // _ZNK3paf7PhScene9GetCameraEi						// paf::PhScene::GetCamera(int)const

    // paf_95748E9E // _ZN3paf5Sound6Output13GetDeviceInfoEjjP26xSettingAudioOutDeviceInfo							// paf::Sound::Output::GetDeviceInfo(unsigned int, unsigned int, xSettingAudioOutDeviceInfo *)
    // paf_9437A62E // _ZN3paf5Sound6Output17ConfigureAudioOutEj32xSettingDisplayAudioOutConfigure					// paf::Sound::Output::ConfigureAudioOut(unsigned int, xSettingDisplayAudioOutConfigure)
    // paf_74AA6AB7 // _ZN3paf5Sound6Output17LoadAudioRegistryEjP24xSettingAudioOutRegistry							// paf::Sound::Output::LoadAudioRegistry(unsigned int, xSettingAudioOutRegistry *)
    // paf_538E485C // _ZN3paf5Sound6Output18GetNumberOfDevicesEj													// paf::Sound::Output::GetNumberOfDevices(unsigned int)
    // paf_CC8004C6 // _ZN3paf5Sound6Output19ReleaseAudioChannelEi													// paf::Sound::Output::ReleaseAudioChannel(int)
    // paf_706B947D // _ZN3paf5Sound6Output19SetDefaultConfigureEv													// paf::Sound::Output::SetDefaultConfigure(void)
    // paf_5AAA5547 // _ZN3paf5Sound6Output20AllocateAudioChannelEv													// paf::Sound::Output::AllocateAudioChannel(void)
    // paf_36362357 // _ZN3paf5Sound6Output4MuteEj20xSettingAudioOutMute											// paf::Sound::Output::Mute(unsigned int, xSettingAudioOutMute)
    // paf_1C71A71C // _ZN3paf5Sound6Output4StopEPv																	// paf::Sound::Output::Stop(void *)
    // paf_21DEB478 // _ZN3paf5Sound6Output6EnableEb																// paf::Sound::Output::Enable(bool)
    // paf_3ADA193F // _ZN3paf5Sound6Output8GetStateEjjP21xSettingAudioOutState										// paf::Sound::Output::GetState(unsigned int, unsigned int, xSettingAudioOutState *)
    // paf_FC23139F // _ZN3paf5Sound6Output9ConfigureEjP29xSettingAudioOutConfigurationP22xSettingAudioOutOptionj	// paf::Sound::Output::Configure(unsigned int, xSettingAudioOutConfiguration *, xSettingAudioOutOption *, unsigned int)

    // paf_76BBC067 // _ZN3paf5Image10Rotation90Ei											// paf::Image::Rotation90(int)
    // paf_BD89CC93 // _ZN3paf5Image10SetSubRectERKNS_9ImageRectE							// paf::Image::SetSubRect(paf::ImageRect const&)
    // paf_1FBFAA13 // _ZN3paf5Image12ToCLUTBufferEb										// paf::Image::ToCLUTBuffer(bool)
    // paf_5B872B03 // _ZN3paf5Image13SetCancelFuncEPFbPvES1_								// paf::Image::SetCancelFunc(bool(*)(void *), void *)
    // paf_9DEF39DE // _ZN3paf5Image15SetGlobalOptionENS_15ImageOptionCodeEi				// paf::Image::SetGlobalOption(paf::ImageOptionCode, int)
    // paf_AA5755FA // _ZN3paf5Image4CopyEv													// paf::Image::Copy(void)
    // paf_11DE1214 // _ZN3paf5Image4LoadEb													// paf::Image::Load(bool)
    // paf_7968B603 // _ZN3paf5Image4OpenEPKcP12malloc_stateNS_11ImageFormatEjj				// paf::Image::Open(char const*, malloc_state *, paf::ImageFormat, unsigned int, unsigned int)
    // paf_F61F19E1 // _ZN3paf5Image4OpenEPvjP12malloc_stateNS_11ImageFormatE				// paf::Image::Open(void *, unsigned int, malloc_state *, paf::ImageFormat)
    // paf_9576C835 // _ZN3paf5Image6ResizeERKNS_11ImageExtentENS_12OpResizeTypeE			// paf::Image::Resize(paf::ImageExtent const&, paf::OpResizeType)
    // paf_4E48E271 // _ZN3paf5Image6UnLoadEv												// paf::Image::UnLoad(void)
    // paf_11395765 // _ZN3paf5Image7OpenGIMEPvj											// paf::Image::OpenGIM(void *, unsigned int)
    // paf_D1B181E0 // _ZN3paf5Image7SetClipERKNS_9ImageRectE								// paf::Image::SetClip(paf::ImageRect const&)
    // paf_C4F74046 // _ZN3paf5Image8ToBufferEb												// paf::Image::ToBuffer(bool)
    // paf_E0AB62A4 // _ZN3paf5Image9Convert32Ev											// paf::Image::Convert32(void)
    // paf_84529ACC // _ZN3paf5Image9SetExtentERKNS_11ImageExtentENS_12OpResizeTypeE		// paf::Image::SetExtent(paf::ImageExtent const&, paf::OpResizeType)
    // paf_C69ECA71 // _ZN3paf5ImageD1Ev													// paf::Image::~Image()

    // paf_868C48A1 // _ZN3paf9HalfImageEPvPKviiii											// paf::HalfImage(void *, void const*, int, int, int, int)
    // paf_41054F69 // _ZN3paf11HalfImageL8EPvPKviiii										// paf::HalfImageL8(void *, void const*, int, int, int, int)

    // paf_FDCB65D3 // _ZN3paf9ImageAttr12SetDecOptionENS_15ImageOptionCodeEi				// paf::ImageAttr::SetDecOption(paf::ImageOptionCode, int)
    // paf_880E3977 // _ZNK3paf9ImageAttr11GetMemWidthEi									// paf::ImageAttr::GetMemWidth(int)const

    // paf_E861FA35 // _ZN3paf7Surface10AttachCLUTERKNS_12SurfaceRCPtrINS_11SurfaceCLUTEEE	// paf::Surface::AttachCLUT(paf::SurfaceRCPtr<paf::SurfaceCLUT> const&)
    // paf_BFA7DC8D // _ZN3paf7Surface10SetFeatureENS0_7FeatureEb							// paf::Surface::SetFeature(paf::Surface::Feature, bool)
    // paf_698E01BE // _ZN3paf7Surface11GetPageSizeEii9ImageMode10ImageOrder				// paf::Surface::GetPageSize(int, int, ImageMode, ImageOrder)
    // paf_BC91AEB3 // _ZN3paf7Surface12RenderTargetEv										// paf::Surface::RenderTarget(void)
    // paf_0CC51D56 // _ZN3paf7Surface4CopyEiPKv10ImageOrderii								// paf::Surface::Copy(int, void const*, ImageOrder, int, int)
    // paf_4EABD9DE // _ZN3paf7Surface4LockEi												// paf::Surface::Lock(int)
    // paf_D51B3CCE // _ZN3paf7Surface6UnlockEv												// paf::Surface::Unlock(void)
    // paf_0C74837D // _ZN3paf7SurfaceC1EPNS_11SurfacePoolEii9ImageMode10ImageOrderbii		// paf::Surface::Surface(paf::SurfacePool *, int, int, ImageMode, ImageOrder, bool, int, int)
    // paf_849CCA15 // _ZN3paf7SurfaceC1Eii9ImageMode10ImageOrderbiPvii						// paf::Surface::Surface(int, int, ImageMode, ImageOrder, bool, int, void *, int, int)
    // paf_278774DE // _ZN3paf7SurfacenwEj													// paf::Surface::operator new(unsigned int)
    // paf_DD8E775C // _ZNK3paf7Surface10GetPagePtrEi										// paf::Surface::GetPagePtr(int)const
    // paf_E81D263A // _ZNK3paf7Surface13GetActivePageENS0_8PageModeE						// paf::Surface::GetActivePage(paf::Surface::PageMode)const

    // paf_DC7E61D3 // _ZN3paf11SurfaceCLUT4CopyEPv											// paf::SurfaceCLUT::Copy(void *)
    // paf_68596AF1 // _ZN3paf11SurfaceCLUTC1EPNS_11SurfacePoolE9ImageModei					// paf::SurfaceCLUT::SurfaceCLUT(paf::SurfacePool *, ImageMode, int)
    // paf_00868264 // _ZN3paf11SurfaceCLUTnwEj												// paf::SurfaceCLUT::operator new(unsigned int)

    // paf_5C54EEAF // _ZNK3paf11SurfacePool11GetFreeSizeEv									// paf::SurfacePool::GetFreeSize(void)const
    // paf_64115670 // _ZN3paf11SurfacePool4FreeEPv											// paf::SurfacePool::Free(void *)
    // paf_34EBB81E // _ZN3paf11SurfacePool8AllocateEii										// paf::SurfacePool::Allocate(int, int)

    // paf_AA8860B9 // _ZN3paf11SurfaceBase18ConvertPixelFormatE9ImageMode					// paf::SurfaceBase::ConvertPixelFormat(ImageMode)
    // paf_B8A630CD // _ZNK3paf11SurfaceBase13PixelsToBytesEi								// paf::SurfaceBase::PixelsToBytes(int)const
    // paf_EDB089C8 // _ZNK3paf11SurfaceBase20GetDevicePixelFormatEv						// paf::SurfaceBase::GetDevicePixelFormat(void)const

    // paf_27527B03 // _ZN3paf6PhFont14GetNumFontListEv										// paf::PhFont::GetNumFontList(void)
    // paf_022BF05A // _ZN3paf6PhFont8SetStyleERKNS_11PhFontStyleE							// paf::PhFont::SetStyle(paf::PhFontStyle const&)
    // paf_40C4C4D9 // _ZN3paf6PhFontC1Ev													// paf::PhFont::PhFont(void)
    // paf_2CC30288 // _ZN3paf6PhFontD1Ev													// paf::PhFont::~PhFont()
    // paf_02AB5840 // _ZNK3paf6PhFont11GetCharInfoENS0_9GlyphTypeEtP18SceFont_t_charInfo	// paf::PhFont::GetCharInfo(paf::PhFont::GlyphType, unsigned short, SceFont_t_charInfo *)const
    // paf_723DB220 // _ZNK3paf6PhFont11GetCharInfoENS0_9GlyphTypeEtPNS0_10BitmapInfoEPi	// paf::PhFont::GetCharInfo(paf::PhFont::GlyphType, unsigned short, paf::PhFont::BitmapInfo *, int *)const

    // paf::PhEvent size: 0x28 ?
    void paf_C2F5EAF9(PhEvent const* phEvent, unsigned int r4, PhWidget* r5, unsigned int r6, int r7, int r8, int r9, int r10); // paf::PhEvent::PhEvent(unsigned int, paf::PhWidget *, unsigned int, int, int, int, int)
    void paf_9C4C1564(PhEvent const* phEvent, unsigned int r4, unsigned int r5, unsigned int r6, int r7, int r8, int r9, int r10); // paf::PhEvent::PhEvent(unsigned int, unsigned int, unsigned int, int, int, int, int)

    // paf_24F6808A // _ZN3paf12PhDispatcher9EventExecEPNS_7PhEventE						// paf::PhDispatcher::EventExec(paf::PhEvent *)

    int paf_FE5A7950(PhHandler const* phHandler, int callbackId, PhEvent* phEvent); // paf::PhHandler::DoCallBack(int, paf::PhEvent *)
    int paf_B60C4316(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandlerProc(paf::PhEvent *)
    int paf_2CBA5A33(PhHandler const* phHandler, int callbackId); // paf::PhHandler::KillTimerCB(int)
    int paf_986427A7(PhHandler const* phHandler, int callbackId, void(*callback)(PhWidget*, PhEvent*, void*), void* unknown); // paf::PhHandler::SetCallBack(int, void(*)(paf::PhWidget *, paf::PhEvent *, void *), void *)
    int paf_818162F2(PhHandler const* phHandler, void(*callback)(PhWidget*, PhEvent*, void*), void* unknown); // paf::PhHandler::SetDeleteCB(void(*)(paf::PhWidget *, paf::PhEvent *, void *), void *)
    int paf_F7D65DC1(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandleFocusEvent(paf::PhEvent *)
    int paf_DBFE46EA(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandlePointEvent(paf::PhEvent *)
    int paf_C051D361(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandleStateEvent(paf::PhEvent *)
    int paf_0C96D94F(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandleSystemEvent(paf::PhEvent *)
    int paf_CE14748C(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandleCommandEvent(paf::PhEvent *)
    int paf_A4D0FDCB(PhHandler const* phHandler, PhEvent* phEvent); // paf::PhHandler::HandleKeycodeEvent(paf::PhEvent *)
    bool paf_4D0CAA13(PhHandler const* phHandler, int callbackId); // paf::PhHandler::IsTimerCB(int)

    // paf_F15A0DE5 // _ZN3paf6PhSpin10SetTextureERKNS_12SurfaceRCPtrINS_7SurfaceEEEi	// paf::PhSpin::SetTexture(paf::SurfaceRCPtr<paf::Surface> const&, int)
    // paf_FDD01957 // _ZN3paf6PhSpin11SetSelectedEi									// paf::PhSpin::SetSelected(int)
    // paf_3A5DB54E // _ZN3paf6PhSpin12SetShowStateEi									// paf::PhSpin::SetShowState(int)
    // paf_69EB7F9A // _ZN3paf6PhSpin14ChangeSelectedEii								// paf::PhSpin::ChangeSelected(int, int)
    // paf_040D12CE // _ZN3paf6PhSpin18HandleKeycodeEventEPNS_7PhEventE					// paf::PhSpin::HandleKeycodeEvent(paf::PhEvent *)
    // paf_053D12C7 // _ZN3paf6PhSpin22HandleFocusSwitchEventEPNS_7PhEventE				// paf::PhSpin::HandleFocusSwitchEvent(paf::PhEvent *)
    // paf_0A03DEFC // _ZN3paf6PhSpin8DrawThisEjb										// paf::PhSpin::DrawThis(unsigned int, bool)
    // paf_0A4091F9 // _ZN3paf6PhSpin8GetStyleEiRi										// paf::PhSpin::GetStyle(int, int &)
    // paf_2030C3B9 // _ZN3paf6PhSpin8SetFocusEPNS_7PhEventEj							// paf::PhSpin::SetFocus(paf::PhEvent *, unsigned int)
    // paf_1DCA42A6 // _ZN3paf6PhSpin8SetStyleEii										// paf::PhSpin::SetStyle(int, int)

    // paf_BFF616B8 // _ZN3paf7PhSPrim17UpdateMatrixColorEPKNS_8PhWidgetERK4vec4	// paf::PhSPrim::UpdateMatrixColor(paf::PhWidget const*, vec4 const&)
    // paf_E31907BE // _ZN3paf7PhSPrim6RenderEPKNS_8PhWidgetERK4vec4b				// paf::PhSPrim::Render(paf::PhWidget const*, vec4 const&, bool)
    // paf_05063ACE // _ZN3paf7PhSPrim8SetStyleEiRK4vec4							// paf::PhSPrim::SetStyle(int, vec4 const&)
    // paf_B6584CE7 // _ZN3paf7PhSPrim8SetStyleEib									// paf::PhSPrim::SetStyle(int, bool)
    // paf_6F1299BE // _ZN3paf7PhSPrim8SetStyleEif									// paf::PhSPrim::SetStyle(int, float)
    // paf_EEE37C22 // _ZN3paf7PhSPrim8SetStyleEii									// paf::PhSPrim::SetStyle(int, int)
    // paf_E3C1B660 // _ZN3paf7PhSPrimC1ERNS_9PhSRenderE							// paf::PhSPrim::PhSPrim(paf::PhSRender &)
    // paf_29C739F4 // _ZNK3paf7PhSPrim8GetStyleEiR4mat4							// paf::PhSPrim::GetStyle(int, mat4 &)const
    // paf_99DB254A // _ZNK3paf7PhSPrim8GetStyleEiR4vec4							// paf::PhSPrim::GetStyle(int, vec4 &)const
    // paf_E2925302 // _ZNK3paf7PhSPrim8GetStyleEiRb								// paf::PhSPrim::GetStyle(int, bool &)const
    // paf_F7B61EE3 // _ZNK3paf7PhSPrim8GetStyleEiRf								// paf::PhSPrim::GetStyle(int, float &)const
    // paf_86E89034 // _ZNK3paf7PhSPrim8GetStyleEiRi								// paf::PhSPrim::GetStyle(int, int &)const

    // paf_A3415D11 // _ZN3paf10PhSPrimDiv6RenderEPKNS_8PhWidgetERK4vec4b			// paf::PhSPrimDiv::Render(paf::PhWidget const*, vec4 const&, bool)
    // paf_275212A0 // _ZN3paf10PhSPrimDiv8SetStyleEiRK4vec4						// paf::PhSPrimDiv::SetStyle(int, vec4 const&)
    // paf_D4579440 // _ZN3paf10PhSPrimDiv8SetStyleEif								// paf::PhSPrimDiv::SetStyle(int, float)
    // paf_CF52B916 // _ZN3paf10PhSPrimDiv8SetStyleEii								// paf::PhSPrimDiv::SetStyle(int, int)
    // paf_2F8B3B85 // _ZN3paf10PhSPrimDivC1ERNS_9PhSRenderE						// paf::PhSPrimDiv::PhSPrimDiv(paf::PhSRender &)
    // paf_0BA57D3D // _ZN3paf10PhSPrimDivD1Ev										// paf::PhSPrimDiv::~PhSPrimDiv()

    bool paf_246B55D0(PhSRender const* sRender, SurfacePtr const& texture); // paf::PhSRender::SetupTexture(paf::SurfaceRCPtr<paf::Surface> const&)const
    bool paf_14B72562(PhSRender const* sRender, SurfacePtr const& texture, vec4 const& r5); // paf::PhSRender::SetupTexture(paf::SurfaceRCPtr<paf::Surface> const&, vec4 const&)const
    int paf_BF575328(PhSRender const* sRender, int style, mat4& value); // paf::PhSRender::GetStyle(int, mat4 &)const
    int paf_DF3A2CA7(PhSRender const* sRender, int style, vec4& value); // paf::PhSRender::GetStyle(int, vec4 &)const
    int paf_57B6F6B2(PhSRender const* sRender, int style, bool& value); // paf::PhSRender::GetStyle(int, bool &)const
    int paf_C35764DF(PhSRender const* sRender, int style, float& value); // paf::PhSRender::GetStyle(int, float &)const
    int paf_9C778A46(PhSRender const* sRender, int style, int& value); // paf::PhSRender::GetStyle(int, int &)const
    int paf_B8979AD7(PhSRender const* sRender, int style, vec4 const& value); // paf::PhSRender::SetStyle(int, vec4 const&)
    int paf_EB793E25(PhSRender const* sRender, int style, bool value); // paf::PhSRender::SetStyle(int, bool)
    int paf_A28C8100(PhSRender const* sRender, int style, float value); // paf::PhSRender::SetStyle(int, float)
    int paf_E22D7B0C(PhSRender const* sRender, int style, int value); // paf::PhSRender::SetStyle(int, int)

    int paf_FF99F7AB(PhSText const* sText); // paf::PhSText::RefreshText(void)
    // paf_F72BABD5 // paf::PhSText::SetFontStyle(paf::PhFontStyle const&)
    int paf_DD32A35C(PhSText const* sText, int style, int& value1, float& value2); // paf::PhSText::GetLayoutStyle(int, int &, float &)
    int paf_6BE9B314(PhSText const* sText, int style, int value1, float value2); // paf::PhSText::SetLayoutStyle(int, int, float)
    void paf_A6F56DD8(PhSText const* sText); // paf::PhSText::Destroy(void)
    bool paf_561CBD17(PhSText const* sText); // paf::PhSText::IsReady(void)
    int paf_FBAF2957(PhSText const* sText, std::wstring const& text); // paf::PhSText::SetText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&)
    int paf_638A0B38(PhSText const* sText, int style, vec4 const& value); // paf::PhSText::SetStyle(int, vec4 const&)
    int paf_8E3B155F(PhSText const* sText, int style, bool value); // paf::PhSText::SetStyle(int, bool)
    int paf_165AD4A6(PhSText const* sText, int style, float value); // paf::PhSText::SetStyle(int, float)
    int paf_983EA578(PhSText const* sText, int style, int value); // paf::PhSText::SetStyle(int, int)
    void paf_66977993(PhSText const* sText, PhSRender& r4, PhSRender* r5); // paf::PhSText::PhSText(paf::PhSRender &, paf::PhSRender*)
    int paf_BE085CD4(PhSText const* sText, int style, vec4& value); // paf::PhSText::GetStyle(int, vec4 &)const
    int paf_CBDF7130(PhSText const* sText, int style, bool& value); // paf::PhSText::GetStyle(int, bool &)const
    int paf_F5116A56(PhSText const* sText, int style, float& value); // paf::PhSText::GetStyle(int, float &)const
    int paf_D2DC1C89(PhSText const* sText, int style, int& value); // paf::PhSText::GetStyle(int, int &)const

    // paf_CA9160F6 // _ZNK3paf9PhNumSpin13GetWidgetTypeEv							// paf::PhNumSpin::GetWidgetType(void)const
    // paf_6C5A6746 // _ZNK3paf9PhNumSpin9IsInheritEPKc								// paf::PhNumSpin::IsInherit(char const*)const
    // paf_59A11C82 // _ZN3paf9PhNumSpin10WidgetTypeEv								// paf::PhNumSpin::WidgetType(void)
    // paf_B923666A // _ZN3paf9PhNumSpin11UpdateStateEv								// paf::PhNumSpin::UpdateState(void)
    // paf_B367A64E // _ZN3paf9PhNumSpin12UpdateLayoutEb							// paf::PhNumSpin::UpdateLayout(bool)
    // paf_233E39D1 // _ZN3paf9PhNumSpin14SetLayoutStyleEiif						// paf::PhNumSpin::SetLayoutStyle(int, int, float)
    // paf_EC70F53F // _ZN3paf9PhNumSpin14SetLayoutStyleEiiif						// paf::PhNumSpin::SetLayoutStyle(int, int, int, float)
    // paf_8043F265 // _ZN3paf9PhNumSpin16SetColor_ontimerERK4vec4					// paf::PhNumSpin::SetColor_ontimer(vec4 const&)
    // paf_85BA32C4 // _ZN3paf9PhNumSpin6CreateEiibiPPNS_7PhSTextEPKi				// paf::PhNumSpin::Create(int, int, bool, int, paf::PhSText **, int const*)
    // paf_24EBED2B // _ZN3paf9PhNumSpin7SetTextERKSbIwSt11char_traitsIwESaIwEEi	// paf::PhNumSpin::SetText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&, int)
    // paf_92A06C2B // _ZN3paf9PhNumSpin8DrawThisEjb								// paf::PhNumSpin::DrawThis(unsigned int, bool)
    // paf_9FF4CD0A // _ZN3paf9PhNumSpin8GetStyleEiRb								// paf::PhNumSpin::GetStyle(int, bool &)
    // paf_15BBE128 // _ZN3paf9PhNumSpin8GetStyleEiiR4vec4							// paf::PhNumSpin::GetStyle(int, int, vec4 &)
    // paf_EE7108A5 // _ZN3paf9PhNumSpin8SetStyleEib								// paf::PhNumSpin::SetStyle(int, bool)
    // paf_FC406066 // _ZN3paf9PhNumSpin8SetStyleEif								// paf::PhNumSpin::SetStyle(int, float)
    // paf_37A6B2F6 // _ZN3paf9PhNumSpin8SetStyleEiiRK4vec4							// paf::PhNumSpin::SetStyle(int, int, vec4 const&)
    // paf_ECB11C5E // _ZN3paf9PhNumSpin8SetStyleEiib								// paf::PhNumSpin::SetStyle(int, int, bool)
    // paf_E4B244BE // _ZN3paf9PhNumSpin8SetStyleEiif								// paf::PhNumSpin::SetStyle(int, int, float)
    // paf_D14F5F81 // _ZN3paf9PhNumSpin8SetStyleEiii								// paf::PhNumSpin::SetStyle(int, int, int)
    // paf_BDA96809 // _ZN3paf9PhNumSpinC1EPNS_8PhWidgetEPNS_8PhAppearE				// paf::PhNumSpin::PhNumSpin(paf::PhWidget *, paf::PhAppear *)
    // paf_BAFCBA67 // _ZN3paf9PhNumSpinC2EPNS_8PhWidgetEPNS_8PhAppearE				// paf::PhNumSpin::PhNumSpin(paf::PhWidget *, paf::PhAppear *)
    // paf_7893B654 // _ZN3paf9PhNumSpinD2Ev										// paf::PhNumSpin::~PhNumSpin()

    // paf_2B50BE7D // _ZNK3paf10PhItemSpin9IsInheritEPKc									// paf::PhItemSpin::IsInherit(char const*)const
    // paf_B39C42DC // _ZN3paf10PhItemSpin10SetTextureERKNS_12SurfaceRCPtrINS_7SurfaceEEEi	// paf::PhItemSpin::SetTexture(paf::SurfaceRCPtr<paf::Surface> const&, int)
    // paf_4C36ABBB // _ZN3paf10PhItemSpin10WidgetTypeEv									// paf::PhItemSpin::WidgetType(void)
    // paf_907A4C6F // _ZN3paf10PhItemSpin11UpdateStateEv									// paf::PhItemSpin::UpdateState(void)
    // paf_B9E387DD // _ZN3paf10PhItemSpin12UpdateLayoutEb									// paf::PhItemSpin::UpdateLayout(bool)
    // paf_E50065BE // _ZN3paf10PhItemSpin14SetLayoutStyleEiiif								// paf::PhItemSpin::SetLayoutStyle(int, int, int, float)
    // paf_CC0D0938 // _ZN3paf10PhItemSpin6CreateEib										// paf::PhItemSpin::Create(int, bool)
    // paf_8AAC61B1 // _ZN3paf10PhItemSpin7SetTextERKSbIwSt11char_traitsIwESaIwEEi			// paf::PhItemSpin::SetText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&, int)
    // paf_688EACFF // _ZN3paf10PhItemSpin8GetStyleEiRb										// paf::PhItemSpin::GetStyle(int, bool &)
    // paf_ADCC6046 // _ZN3paf10PhItemSpin8GetStyleEiiR4vec4								// paf::PhItemSpin::GetStyle(int, int, vec4 &)
    // paf_A08ABACC // _ZN3paf10PhItemSpin8SetStyleEib										// paf::PhItemSpin::SetStyle(int, bool)
    // paf_EDE62D3D // _ZN3paf10PhItemSpin8SetStyleEiiRK4vec4								// paf::PhItemSpin::SetStyle(int, int, vec4 const&)
    // paf_96599FE7 // _ZN3paf10PhItemSpin8SetStyleEiib										// paf::PhItemSpin::SetStyle(int, int, bool)
    // paf_62DCA3E2 // _ZN3paf10PhItemSpin8SetStyleEiif										// paf::PhItemSpin::SetStyle(int, int, float)
    // paf_4E348797 // _ZN3paf10PhItemSpin8SetStyleEiii										// paf::PhItemSpin::SetStyle(int, int, int)
    // paf_A4514F28 // _ZN3paf10PhItemSpinC1EPNS_8PhWidgetEPNS_8PhAppearE					// paf::PhItemSpin::PhItemSpin(paf::PhWidget *, paf::PhAppear *)
    // paf_D6A50AAC // _ZN3paf10PhItemSpinC2EPNS_8PhWidgetEPNS_8PhAppearE					// paf::PhItemSpin::PhItemSpin(paf::PhWidget *, paf::PhAppear *)
    // paf_97E124F1 // _ZN3paf10PhItemSpinD2Ev												// paf::PhItemSpin::~PhItemSpin()

    // paf_CACDFB2D // _ZN3paf13PhAppearPlane10SetTextureERKNS_12SurfaceRCPtrINS_7SurfaceEEEi	// paf::PhAppearPlane::SetTexture(paf::SurfaceRCPtr<paf::Surface> const&, int)
    // paf_D7F0A558 // _ZN3paf13PhAppearPlane11RenderStateEjb									// paf::PhAppearPlane::RenderState(unsigned int, bool)
    // paf_23CCCCBB // _ZN3paf13PhAppearPlane8SetStyleEii										// paf::PhAppearPlane::SetStyle(int, int)

    void paf_8C7A6C86(void* _this);

    // paf_51D70976 // _ZNK3paf8PhWidget10GetTextureERNS_12SurfaceRCPtrINS_7SurfaceEEEi		// paf::PhWidget::GetTexture(paf::SurfaceRCPtr<paf::Surface> &, int)const
    // paf_44CDAE21 // _ZNK3paf8PhWidget12GetLayoutPosERiS1_S1_R4vec4						// paf::PhWidget::GetLayoutPos(int &, int &, int &, vec4 &)const
    // paf_3242B3F4 // _ZNK3paf8PhWidget13GetLayoutSizeERiS1_S1_R4vec4						// paf::PhWidget::GetLayoutSize(int &, int &, int &, vec4 &)const
    // paf_E1654E20 // _ZNK3paf8PhWidget15GetEditTextPartERi								// paf::PhWidget::GetEditTextPart(int &)const
    // paf_0A9E290A // _ZNK3paf8PhWidget7GetTextERSbIwSt11char_traitsIwESaIwEEi				// paf::PhWidget::GetText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > &, int)const
    // paf_F5C65829 // _ZNK3paf8PhWidget9IsInheritEPKc										// paf::PhWidget::IsInherit(char const*)const
    // paf_65F530A4 // _ZN3paf8PhWidget10SetColor32Ej										// paf::PhWidget::SetColor32(unsigned int)
    // paf_2557E245 // _ZN3paf8PhWidget10SetPostureERK4vec4S3_PS0_							// paf::PhWidget::SetPosture(vec4 const&, vec4 const&, paf::PhWidget*)
    // paf_B84F742B // _ZN3paf8PhWidget10SetTextureERKNS_12SurfaceRCPtrINS_7SurfaceEEEi		// paf::PhWidget::SetTexture(paf::SurfaceRCPtr<paf::Surface> const&, int)
    // paf_546B3D02 // _ZN3paf8PhWidget10WidgetTypeEv										// paf::PhWidget::WidgetType(void)
    // paf_3F4844B4 // _ZN3paf8PhWidget11EndEditTextEv										// paf::PhWidget::EndEditText(void)
    // paf_190D4130 // _ZN3paf8PhWidget11RegistChildEPS0_									// paf::PhWidget::RegistChild(paf::PhWidget*)
    // paf_593FB1E5 // _ZN3paf8PhWidget11RemoveChildEPKS0_									// paf::PhWidget::RemoveChild(paf::PhWidget const*)
    // paf_D75F6183 // _ZN3paf8PhWidget11RemoveChildEi										// paf::PhWidget::RemoveChild(int)
    // paf_2CE5FF1D // _ZN3paf8PhWidget11SetDispatchEj										// paf::PhWidget::SetDispatch(unsigned int)
    // paf_D1CDDADD // _ZN3paf8PhWidget11UpdateStateEv										// paf::PhWidget::UpdateState(void)
    // paf_6846D51A // _ZN3paf8PhWidget12ReleaseFocusEb										// paf::PhWidget::ReleaseFocus(bool)
    // paf_51F323AA // _ZN3paf8PhWidget12SetFocusAnimEii									// paf::PhWidget::SetFocusAnim(int, int)
    // paf_AFB4ECB9 // _ZN3paf8PhWidget12SetLayoutPosEiii4vec4								// paf::PhWidget::SetLayoutPos(int, int, int, vec4)
    // paf_4A6A2F04 // _ZN3paf8PhWidget12UpdateLayoutEb										// paf::PhWidget::UpdateLayout(bool)
    // paf_10893289 // _ZN3paf8PhWidget12UpdateMatrixEv										// paf::PhWidget::UpdateMatrix(void)
    // paf_2BD63EAD // _ZN3paf8PhWidget13BeginEditTextERKNS_10PhEditText8OskParamEi			// paf::PhWidget::BeginEditText(paf::PhEditText::OskParam const&, int)
    // paf_016A3B00 // _ZN3paf8PhWidget13DestroyWidgetEv									// paf::PhWidget::DestroyWidget(void)
    // paf_EE3D6DD0 // _ZN3paf8PhWidget13SetAppearanceEPNS_8PhAppearE						// paf::PhWidget::SetAppearance(paf::PhAppear *)
    // paf_6B2A00C5 // _ZN3paf8PhWidget13SetLayoutSizeEiii4vec4								// paf::PhWidget::SetLayoutSize(int, int, int, vec4)
    // paf_613A24BF // _ZN3paf8PhWidget13UpdateCamerasEv									// paf::PhWidget::UpdateCameras(void)
    // paf_384F93FC // _ZN3paf8PhWidget13UpdatePrepareEv									// paf::PhWidget::UpdatePrepare(void)
    // paf_695E35BE // _ZN3paf8PhWidget14GetLayoutStyleEiRiRf								// paf::PhWidget::GetLayoutStyle(int, int &, float &)
    // paf_4B619490 // _ZN3paf8PhWidget14GetLayoutStyleEiRiS1_S1_R4vec4						// paf::PhWidget::GetLayoutStyle(int, int &, int &, int &, vec4 &)
    // paf_B36CA4B4 // _ZN3paf8PhWidget14GetLayoutStyleEiiRiRf								// paf::PhWidget::GetLayoutStyle(int, int, int &, float &)
    // paf_00C9AFA5 // _ZN3paf8PhWidget14GetLayoutStyleEiiRiS1_S1_R4vec4					// paf::PhWidget::GetLayoutStyle(int, int, int &, int &, int &, vec4 &)
    // paf_F6E0A48F // _ZN3paf8PhWidget14SetLayoutStyleEiif									// paf::PhWidget::SetLayoutStyle(int, int, float)
    // paf_EF6C6834 // _ZN3paf8PhWidget14SetLayoutStyleEiiif								// paf::PhWidget::SetLayoutStyle(int, int, int, float)
    // paf_9DF5AAD4 // _ZN3paf8PhWidget14SetLayoutStyleEiiii4vec4							// paf::PhWidget::SetLayoutStyle(int, int, int, int, vec4)
    // paf_D6135FC4 // _ZN3paf8PhWidget14SetLayoutStyleEiiiii4vec4							// paf::PhWidget::SetLayoutStyle(int, int, int, int, int, vec4)
    // paf_ADF743E4 // _ZN3paf8PhWidget14SetPos_ontimerERK4vec4PS0_							// paf::PhWidget::SetPos_ontimer(vec4 const&, paf::PhWidget*)
    void paf_67437488(PhWidget const* widget, vec4 const& rotation, PhWidget* widgetTemplate, int r6); // paf::PhWidget::SetRot_ontimer(vec4 const&, paf::PhWidget*, int)
    bool paf_B5505299(PhWidget const* widget, PhWidget* child1, PhWidget* child2, int flag); // paf::PhWidget::ReorderChildren(paf::PhWidget const*, paf::PhWidget const*, int)
    // paf_5FD00911 // _ZN3paf8PhWidget15SetSize_ontimerERK4vec4							// paf::PhWidget::SetSize_ontimer(vec4 const&)
    // paf_BF4B155C // _ZN3paf8PhWidget15UpdateLayoutPosEv									// paf::PhWidget::UpdateLayoutPos(void)
    // paf_6BDB86A9 // _ZN3paf8PhWidget16SetMetaAlphaModeEi									// paf::PhWidget::SetMetaAlphaMode(int)
    // paf_73C6B7C4 // _ZN3paf8PhWidget16SetScale_ontimerERK4vec4							// paf::PhWidget::SetScale_ontimer(vec4 const&)
    // paf_DF031EDD // _ZN3paf8PhWidget16UpdateLayoutSizeEv									// paf::PhWidget::UpdateLayoutSize(void)
    // paf_E434952C // _ZN3paf8PhWidget17GetLayoutPosValueEv								// paf::PhWidget::GetLayoutPosValue(void)
    // paf_B527E7E5 // _ZN3paf8PhWidget17HandleAnalogEventEPNS_7PhEventE					// paf::PhWidget::HandleAnalogEvent(paf::PhEvent *)
    // paf_9DF5EBC4 // _ZN3paf8PhWidget17UpdateLayoutStyleEi								// paf::PhWidget::UpdateLayoutStyle(int)
    // paf_FBAD1D7A // _ZN3paf8PhWidget18GetLayoutSizeValueEv								// paf::PhWidget::GetLayoutSizeValue(void)
    // paf_26ED24A6 // _ZN3paf8PhWidget18HandleFocusInEventEPNS_7PhEventE					// paf::PhWidget::HandleFocusInEvent(paf::PhEvent *)
    // paf_4F3E14A7 // _ZN3paf8PhWidget18HandleKeycodeEventEPNS_7PhEventE					// paf::PhWidget::HandleKeycodeEvent(paf::PhEvent *)
    // paf_8E8DB4B0 // _ZN3paf8PhWidget19HandleFocusOutEventEPNS_7PhEventE					// paf::PhWidget::HandleFocusOutEvent(paf::PhEvent *)
    // paf_2B86EEC6 // _ZN3paf8PhWidget20SetMetaAlpha_ontimerEfb							// paf::PhWidget::SetMetaAlpha_ontimer(float, bool)
    // paf_AD484F91 // _ZN3paf8PhWidget22HandleFocusSwitchEventEPNS_7PhEventE				// paf::PhWidget::HandleFocusSwitchEvent(paf::PhEvent *)
    // paf_A921D353 // paf::PhWidget::GetPos(paf::PhWidget*, vec4 const&)
    // paf_C2E555BA // paf::PhWidget::GetRot(paf::PhWidget*, vec4 const&, int)
    // paf_683C91D8 // paf::PhWidget::LookAt(paf::PhWidget*, vec4 const&, paf::PhWidget*, vec4 const&)
    // paf_9AEFF88B // paf::PhWidget::LookAt(vec4 const&, vec4 const&)
    // paf_0241B884 // _ZN3paf8PhWidget7SetTextERKSbIwSt11char_traitsIwESaIwEEi				// paf::PhWidget::SetText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&, int)
    void paf_63D446B8(PhWidget const* widget, unsigned int r4, bool r6); // paf::PhWidget::DrawThis(unsigned int, bool)
    // paf_3CF24218 // _ZN3paf8PhWidget8GetChildEi											// paf::PhWidget::GetChild(int)
    // paf_D314EF39 // _ZN3paf8PhWidget8GetStyleEiR4mat4									// paf::PhWidget::GetStyle(int, mat4 &)
    // paf_9379F77A // _ZN3paf8PhWidget8GetStyleEiR4vec4									// paf::PhWidget::GetStyle(int, vec4 &)
    // paf_1E54DB1E // _ZN3paf8PhWidget8GetStyleEiRb										// paf::PhWidget::GetStyle(int, bool &)
    // paf_7EF048AB // _ZN3paf8PhWidget8GetStyleEiRf										// paf::PhWidget::GetStyle(int, float &)
    // paf_547917DF // _ZN3paf8PhWidget8GetStyleEiRi										// paf::PhWidget::GetStyle(int, int &)
    // paf_C03F89E6 // _ZN3paf8PhWidget8GetStyleEiiR4mat4									// paf::PhWidget::GetStyle(int, int, mat4 &)
    // paf_58F29B96 // _ZN3paf8PhWidget8GetStyleEiiR4vec4									// paf::PhWidget::GetStyle(int, int, vec4 &)
    // paf_5FFC22E1 // _ZN3paf8PhWidget8GetStyleEiiRb										// paf::PhWidget::GetStyle(int, int, bool &)
    // paf_A2108B85 // _ZN3paf8PhWidget8GetStyleEiiRf										// paf::PhWidget::GetStyle(int, int, float &)
    // paf_B4F7ED4F // _ZN3paf8PhWidget8GetStyleEiiRi										// paf::PhWidget::GetStyle(int, int, int &)
    // paf_D2649242 // _ZN3paf8PhWidget8SetFocusEPNS_7PhEventEj								// paf::PhWidget::SetFocus(paf::PhEvent *, unsigned int)
    // paf_F467C45F // _ZN3paf8PhWidget8SetStyleEiRK4vec4									// paf::PhWidget::SetStyle(int, vec4 const&)
    // paf_7A7BCEED // _ZN3paf8PhWidget8SetStyleEib											// paf::PhWidget::SetStyle(int, bool)
    // paf_A97D0803 // _ZN3paf8PhWidget8SetStyleEif											// paf::PhWidget::SetStyle(int, float)
    // paf_04EC636E // _ZN3paf8PhWidget8SetStyleEii											// paf::PhWidget::SetStyle(int, int)
    // paf_E8129023 // _ZN3paf8PhWidget8SetStyleEiiRK4vec4									// paf::PhWidget::SetStyle(int, int, vec4 const&)
    // paf_B902CB91 // _ZN3paf8PhWidget8SetStyleEiib										// paf::PhWidget::SetStyle(int, int, bool)
    // paf_38162763 // _ZN3paf8PhWidget8SetStyleEiif										// paf::PhWidget::SetStyle(int, int, float)
    // paf_88161054 // _ZN3paf8PhWidget8SetStyleEiii										// paf::PhWidget::SetStyle(int, int, int)
    PhWidget* paf_D557F850(PhWidget const* widget, char const* name, int r5); // paf::PhWidget::FindChild(char const*, int)
    void paf_24A977F7(PhWidget const* widget, bool pause); // paf::PhWidget::PauseAnim(bool)
    void paf_C028CB7C(PhWidget const* widget, bool start); // paf::PhWidget::StartAnim(bool)
    void paf_738BAAC0(PhWidget const* widget); // paf::PhWidget::~PhWidget()

    // paf_9FBCD5C8 // _ZNK3paf7PhPlane9IsInheritEPKc					// paf::PhPlane::IsInherit(char const*)const
    // paf_10DEDCC7 // _ZN3paf7PhPlane10WidgetTypeEv					// paf::PhPlane::WidgetType(void)
    void paf_D0197A7D(PhPlane const* plane, PhWidget* parent, void* phAppear); // paf::PhPlane::PhPlane(paf::PhWidget *, paf::PhAppear *)
    // paf_CC58846C // _ZN3paf7PhPlaneC2EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhPlane::PhPlane(paf::PhWidget *, paf::PhAppear *)
    void paf_0C16A258(PhPlane const* plane); // paf::PhPlane::~PhPlane()
    // paf_E36C18F5 // _ZN3paf10PhPlaneDiv10WidgetTypeEv				// paf::PhPlaneDiv::WidgetType(void)

    // paf_4569ABC3 // _ZN3paf6PhText10InsertTextEjRKSbIwSt11char_traitsIwESaIwEE	// paf::PhText::InsertText(unsigned int, std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&)
    // paf_FE119299 // _ZN3paf6PhText10SetVScrollEPNS_8PhScrollE					// paf::PhText::SetVScroll(paf::PhScroll *)
    // paf_B7DFCE90 // _ZN3paf6PhText10WidgetTypeEv									// paf::PhText::WidgetType(void)
    // paf_C7CF2A06 // _ZN3paf6PhText12SetFirstLineEf								// paf::PhText::SetFirstLine(float)
    // paf_EB73AD01 // _ZN3paf6PhText12SetFontStyleERKNS_11PhFontStyleE				// paf::PhText::SetFontStyle(paf::PhFontStyle const&)
    // paf_84E6B20D // _ZN3paf6PhText13EnsureVisibleEv								// paf::PhText::EnsureVisible(void)
    // paf_2DB4683D // _ZN3paf6PhText13SetCurrentPosEj								// paf::PhText::SetCurrentPos(unsigned int)
    // paf_BD01AEF9 // _ZN3paf6PhText14ReleaseSurfaceEv								// paf::PhText::ReleaseSurface(void)
    // paf_A0118D9E // _ZN3paf6PhText14RemoveAllAttrsEv								// paf::PhText::RemoveAllAttrs(void)
    // paf_91CD1263 // _ZN3paf6PhText15SetColumnOffsetEf							// paf::PhText::SetColumnOffset(float)
    // paf_2DBA5B93 // _ZN3paf6PhText21SetPrivateSurfacePoolEPNS_11SurfacePoolE		// paf::PhText::SetPrivateSurfacePool(paf::SurfacePool *)
    // paf_402E693B // _ZN3paf6PhText6LineUpEj										// paf::PhText::LineUp(unsigned int)
    // paf_74093C9A // _ZN3paf6PhText7AddAttrENS_14PhTextAttrTypeEjj				// paf::PhText::AddAttr(paf::PhTextAttrType, unsigned int, unsigned int)
    // paf_022FDDB8 // _ZN3paf6PhText7SetSizeEfff									// paf::PhText::SetSize(float, float, float)
    // paf_E75F9969 // _ZN3paf6PhText8LineDownEj									// paf::PhText::LineDown(unsigned int)
    // paf_6B620D94 // _ZN3paf6PhText9EraseTextEjj									// paf::PhText::EraseText(unsigned int, unsigned int)
    // paf_201528C1 // _ZN3paf6PhText9ShowCaretEb									// paf::PhText::ShowCaret(bool)
    void paf_7F0930C6(PhText const* text, PhWidget* parent, void* phAppear); // paf::PhText::PhText(paf::PhWidget *, paf::PhAppear *)
    // paf_304EAE6F // _ZNK3paf6PhText12GetFirstLineEv								// paf::PhText::GetFirstLine(void)const
    // paf_E8355FCC // _ZNK3paf6PhText12GetLineCountEv								// paf::PhText::GetLineCount(void)const
    // paf_65036474 // _ZNK3paf6PhText12GetTextWidthEv								// paf::PhText::GetTextWidth(void)const
    // paf_77479F6F // _ZNK3paf6PhText13GetCurrentPosEv								// paf::PhText::GetCurrentPos(void)const
    // paf_20477524 // _ZNK3paf6PhText13GetLineHeightEv								// paf::PhText::GetLineHeight(void)const
    // paf_3F10A8D7 // _ZNK3paf6PhText13GetTextLengthEv								// paf::PhText::GetTextLength(void)const
    // paf_4F5319E0 // _ZNK3paf6PhText14GetCurrentLineEv							// paf::PhText::GetCurrentLine(void)const
    // paf_9196EEB8 // _ZNK3paf6PhText15GetColumnOffsetEv							// paf::PhText::GetColumnOffset(void)const
    // paf_68D2B06D // _ZNK3paf6PhText15GetVisibleLinesEv							// paf::PhText::GetVisibleLines(void)const

    // paf_BA6D149A // _ZN3paf11PhLabelPrim10WidgetTypeEv								// paf::PhLabelPrim::WidgetType(void)
    // paf_44F95B67 // _ZN3paf11PhLabelPrimC1EPNS_8PhWidgetEPNS_8PhAppearE				// paf::PhLabelPrim::PhLabelPrim(paf::PhWidget *, paf::PhAppear *)
    // paf_7D594F19 // _ZN3paf14PhLabelPrimDivC1EPNS_8PhWidgetEPNS_8PhAppearE			// paf::PhLabelPrimDiv::PhLabelPrimDiv(paf::PhWidget *, paf::PhAppear *)

    // paf_DDD4ACF6 // _ZN3paf11PhLabelText10WidgetTypeEv								// paf::PhLabelText::WidgetType(void)
    // paf_429ED666 // _ZN3paf11PhLabelText12SetLineColorEjRK4vec4						// paf::PhLabelText::SetLineColor(unsigned int, vec4 const&)
    // paf_FDD0EB53 // _ZN3paf11PhLabelText14ReleaseSurfaceEj							// paf::PhLabelText::ReleaseSurface(unsigned int)
    // paf_A3224451 // _ZN3paf11PhLabelText14SetLineVisibleEjb							// paf::PhLabelText::SetLineVisible(unsigned int, bool)
    // paf_96486AF8 // _ZN3paf11PhLabelText15SetColumnOffsetEf							// paf::PhLabelText::SetColumnOffset(float)
    // paf_D11A3565 // _ZN3paf11PhLabelText15SetShadowRenderEPNS_9PhSRenderE			// paf::PhLabelText::SetShadowRender(paf::PhSRender *)
    // paf_CB864F5D // _ZN3paf11PhLabelText21SetPrivateSurfacePoolEPNS_11SurfacePoolE	// paf::PhLabelText::SetPrivateSurfacePool(paf::SurfacePool *)
    // paf_20183B78 // _ZN3paf11PhLabelTextC1EPNS_8PhWidgetEPNS_8PhAppearE				// paf::PhLabelText::PhLabelText(paf::PhWidget *, paf::PhAppear *)
    // paf_B71DC906 // _ZNK3paf11PhLabelText12GetLineCountEv							// paf::PhLabelText::GetLineCount(void)const
    // paf_161E2246 // _ZNK3paf11PhLabelText12GetMaxHeightEv							// paf::PhLabelText::GetMaxHeight(void)const
    // paf_3B002423 // _ZNK3paf11PhLabelText12GetTextWidthEv							// paf::PhLabelText::GetTextWidth(void)const
    // paf_46E3E3FD // _ZNK3paf11PhLabelText13GetLineHeightEv							// paf::PhLabelText::GetLineHeight(void)const
    // paf_2B35D7DD // _ZNK3paf11PhLabelText14GetMaxAscenderEv							// paf::PhLabelText::GetMaxAscender(void)const

    // paf_BF66BF2D // _ZN3paf10PhCheckBox10WidgetTypeEv					// paf::PhCheckBox::WidgetType(void)
    // paf_B7377945 // _ZN3paf10PhCheckBox6CreateEv							// paf::PhCheckBox::Create(void)
    // paf_5A85BEFC // _ZN3paf10PhCheckBox8SetCheckEbb						// paf::PhCheckBox::SetCheck(bool, bool)
    // paf_176E3BC4 // _ZN3paf10PhCheckBoxC1EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhCheckBox::PhCheckBox(paf::PhWidget *, paf::PhAppear *)

    // paf_90F4F801 // _ZN3paf14PhCheckBoxList10WidgetTypeEv				// paf::PhCheckBoxList::WidgetType(void)
    // paf_EEFAA794 // _ZN3paf14PhCheckBoxList8GetCheckEi					// paf::PhCheckBoxList::GetCheck(int)
    // paf_6B57CB4D // _ZN3paf14PhCheckBoxList8SetCheckEibb					// paf::PhCheckBoxList::SetCheck(int, bool, bool)

    // paf_55063D70 // _ZN3paf10PhInfoList10SetItemNumEi								// paf::PhInfoList::SetItemNum(int)
    // paf_F7630798 // _ZN3paf10PhInfoList10WidgetTypeEv								// paf::PhInfoList::WidgetType(void)
    // paf_0D1BA494 // _ZN3paf10PhInfoList13SetSelectableEibb							// paf::PhInfoList::SetSelectable(int, bool, bool)
    // paf_318C080C // _ZN3paf10PhInfoList13SetVisibleTopEf								// paf::PhInfoList::SetVisibleTop(float)
    // paf_BEDFF5EE // _ZN3paf10PhInfoList14GetPartsWidgetEi							// paf::PhInfoList::GetPartsWidget(int)
    // paf_D8EB2AD2 // _ZN3paf10PhInfoList21SetPrivateSurfacePoolEPNS_11SurfacePoolE	// paf::PhInfoList::SetPrivateSurfacePool(paf::SurfacePool *)
    // paf_EE05CF53 // _ZN3paf10PhInfoList6CreateEif									// paf::PhInfoList::Create(int, float)
    // paf_816D1A8F // _ZN3paf10PhInfoListC1EPNS_8PhWidgetEPNS_8PhAppearE				// paf::PhInfoList::PhInfoList(paf::PhWidget *, paf::PhAppear *)

    // paf_A98865F8 // _ZN3paf10PhMenuList10WidgetTypeEv					// paf::PhMenuList::WidgetType(void)
    // paf_4618F156 // _ZN3paf10PhMenuList11SetSelectedEi					// paf::PhMenuList::SetSelected(int)
    // paf_1CD57819 // _ZN3paf10PhMenuList12SetShowStateEii					// paf::PhMenuList::SetShowState(int, int)
    // paf_3E1D246B // _ZN3paf10PhMenuList14ChangeSelectedEi				// paf::PhMenuList::ChangeSelected(int)
    // paf_88DB3841 // _ZN3paf10PhMenuList14SetSelectedPosEi				// paf::PhMenuList::SetSelectedPos(int)
    // paf_B9502D8B // _ZN3paf10PhMenuListC1EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhMenuList::PhMenuList(paf::PhWidget *, paf::PhAppear *)

    // paf_7531D5C0 // _ZN3paf6PhList10SetItemNumEi						// paf::PhList::SetItemNum(int)
    // paf_D64EDE7C // _ZN3paf6PhList10WidgetTypeEv						// paf::PhList::WidgetType(void)
    // paf_3F5AB405 // _ZN3paf6PhList12GetShowStateEi					// paf::PhList::GetShowState(int)
    // paf_AF27EE12 // _ZN3paf6PhList12PopBackLabelEi					// paf::PhList::PopBackLabel(int)
    // paf_B624302F // _ZN3paf6PhList12PushBackItemEi					// paf::PhList::PushBackItem(int)
    // paf_FEBB5DBB // _ZN3paf6PhList13SetVisibleTopEi					// paf::PhList::SetVisibleTop(int)
    // paf_14EBB064 // _ZN3paf6PhList14GetPartsWidgetEi					// paf::PhList::GetPartsWidget(int)
    // paf_46CC88BE // _ZN3paf6PhList15SetShadowRenderEPNS_9PhSRenderE	// paf::PhList::SetShadowRender(paf::PhSRender *)
    // paf_094CD214 // _ZN3paf6PhList17PushBackLabelTextEi				// paf::PhList::PushBackLabelText(int)
    // paf_AED08D9E // _ZN3paf6PhList18PushBackLabelImageEi				// paf::PhList::PushBackLabelImage(int)
    // paf_C3F7B60E // _ZN3paf6PhList19PushBackLabelShadowEi			// paf::PhList::PushBackLabelShadow(int)
    // paf_9F143A8C // _ZN3paf6PhList6RedrawEv							// paf::PhList::Redraw(void)
    // paf_5903BC00 // _ZN3paf6PhListC1EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhList::PhList(paf::PhWidget *, paf::PhAppear *)

    // paf_26E9507E // _ZN3paf10MessageBox10HideDeleteEv															// paf::MessageBox::HideDelete(void)
    // paf_7001CAC7 // _ZN3paf10MessageBox12GetSpaceInfoEPNS0_9SpaceInfoE											// paf::MessageBox::GetSpaceInfo(paf::MessageBox::SpaceInfo *)
    // paf_C84F0B21 // _ZN3paf10MessageBox12SetLayoutPosEii															// paf::MessageBox::SetLayoutPos(int, int)
    // paf_6F8663E4 // _ZN3paf10MessageBox15SetProgressTextERKSbIwSt11char_traitsIwESaIwEEi							// paf::MessageBox::SetProgressText(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > const&, int)
    // paf_84D7A733 // _ZN3paf10MessageBox25SetMessageBoxSoundHandlerEPFvNS0_9SoundTypeEE							// paf::MessageBox::SetMessageBoxSoundHandler(void(*)(paf::MessageBox::SoundType))
    // paf_1F31959E // _ZN3paf10MessageBox25SetQueryButtonInfoHandlerEPFbNS0_10ButtonTypeEPNS0_10ButtonInfoEE		// paf::MessageBox::SetQueryButtonInfoHandler(bool(*)(paf::MessageBox::ButtonType, paf::MessageBox::ButtonInfo *))
    // paf_8BC095CF // _ZN3paf10MessageBox26SetQueryTextureInfoHandlerEPFbNS0_11TextureTypeEPNS0_11TextureInfoEE	// paf::MessageBox::SetQueryTextureInfoHandler(bool(*)(paf::MessageBox::TextureType, paf::MessageBox::TextureInfo *))
    // paf_84FC5B16 // _ZN3paf10MessageBox30SetQueryProgressBarInfoHandlerEPFvPNS0_15ProgressBarInfoEE				// paf::MessageBox::SetQueryProgressBarInfoHandler(void(*)(paf::MessageBox::ProgressBarInfo *))

    // paf_E801C345 // _ZN3paf10PhProgress10WidgetTypeEv					// paf::PhProgress::WidgetType(void)
    // paf_301F3376 // _ZN3paf10PhProgress11ChangeValueEffi					// paf::PhProgress::ChangeValue(float, float, int)
    // paf_BEC5537F // _ZN3paf10PhProgress11SetMaxValueEf					// paf::PhProgress::SetMaxValue(float)
    // paf_15FD7978 // _ZN3paf10PhProgress15RequestSetValueEf				// paf::PhProgress::RequestSetValue(float)
    // paf_2883F1FC // _ZN3paf10PhProgress18RequestChangeValueEffi			// paf::PhProgress::RequestChangeValue(float, float, int)
    // paf_9FB0F27B // _ZN3paf10PhProgress8SetValueEf						// paf::PhProgress::SetValue(float)
    // paf_4D930842 // _ZN3paf10PhProgressC1EPNS_8PhWidgetEPNS_8PhAppearE	// paf::PhProgress::PhProgress(paf::PhWidget *, paf::PhAppear *)

    // paf_C88CA4B2 // _ZN3paf12PhLevelMeter10WidgetTypeEv						// paf::PhLevelMeter::WidgetType(void)
    // paf_D8D768ED // _ZN3paf12PhLevelMeter11SetSelectedEi						// paf::PhLevelMeter::SetSelected(int)
    // paf_24A9E5BA // _ZN3paf12PhLevelMeter6CreateEii							// paf::PhLevelMeter::Create(int, int)
    // paf_A3770DD7 // _ZN3paf12PhLevelMeterC1EPNS_8PhWidgetEPNS_8PhAppearE		// paf::PhLevelMeter::PhLevelMeter(paf::PhWidget *, paf::PhAppear *)

    // paf_545D47A2 // _ZN3paf7PhClock10WidgetTypeEv						// paf::PhClock::WidgetType(void)
    // paf_F8DB34C7 // _ZN3paf7PhClock15SetShadowRenderEPNS_9PhSRenderE		// paf::PhClock::SetShadowRender(paf::PhSRender *)
    // paf_BBFF3B2F // _ZN3paf7PhClock7GetTimeERNS0_10datetime_tE			// paf::PhClock::GetTime(paf::PhClock::datetime_t &)
    // paf_1B75E85F // _ZN3paf7PhClock7SetTimeERKNS0_10datetime_tE			// paf::PhClock::SetTime(paf::PhClock::datetime_t const&)
    // paf_2293AB67 // _ZN3paf7PhClockC1EPNS_8PhWidgetE						// paf::PhClock::PhClock(paf::PhWidget *)

    // paf_9D191F72 // _ZN3paf8DateTime13SetDateFormatEPKw					// paf::DateTime::SetDateFormat(wchar_t const*)
    // paf_2D388628 // _ZN3paf8DateTime13SetTimeFormatEPKw					// paf::DateTime::SetTimeFormat(wchar_t const*)
    // paf_D251AE84 // _ZN3paf8DateTime17SetDateTimeFormatEPKw				// paf::DateTime::SetDateTimeFormat(wchar_t const*)
    // paf_D4946610 // _ZN3paf8DateTime3NowEv								// paf::DateTime::Now(void)
    // paf_ED5FDE32 // _ZN3paf8DateTime6FormatEPwjPKw						// paf::DateTime::Format(wchar_t *, unsigned int, wchar_t const*)

    // paf_24A5BD6B // _ZN3paf8PhButton10WidgetTypeEv						// paf::PhButton::WidgetType(void)
    // paf_21C770A3 // _ZN3paf8PhButtonC1EPNS_8PhWidgetEPNS_8PhAppearE		// paf::PhButton::PhButton(paf::PhWidget *, paf::PhAppear *)

    // paf_3806365F // _ZN3paf8PhIPAddr10WidgetTypeEv						// paf::PhIPAddr::WidgetType(void)
    // paf_B361BDA6 // _ZN3paf8PhIPAddr8GetValueEPhi						// paf::PhIPAddr::GetValue(unsigned char *, int)
    // paf_0ACCBD0C // _ZN3paf8PhIPAddr8SetValueEPh							// paf::PhIPAddr::SetValue(unsigned char *)

    // paf_009207F4 // _ZN3paf8PhScroll10WidgetTypeEv						// paf::PhScroll::WidgetType(void)
    // paf_1C7E659C // _ZN3paf8PhScroll11ChangeValueEffi					// paf::PhScroll::ChangeValue(float, float, int)
    // paf_D965C0BE // _ZN3paf8PhScroll11SetMaxValueEf						// paf::PhScroll::SetMaxValue(float)
    // paf_1C83C0B6 // _ZN3paf8PhScroll16SetVisibleAmountEf					// paf::PhScroll::SetVisibleAmount(float)
    // paf_1AD29E49 // _ZN3paf8PhScroll8SetValueEf							// paf::PhScroll::SetValue(float)
    // paf_BC2C23A8 // _ZN3paf8PhScrollC1EPNS_8PhWidgetEPNS_8PhAppearE		// paf::PhScroll::PhScroll(paf::PhWidget *, paf::PhAppear *)

    // Xmb items ?
    // paf_E02A30D5 // _ZN3paf14PhAppearXmItem20SetDefaultLabelColorERK4vec4									// paf::PhAppearXmItem::SetDefaultLabelColor(vec4 const&)

    // paf_55FE8B14 // _ZN3paf8PhXmItem10BlinkStartEf															// paf::PhXmItem::BlinkStart(float)
    // paf_C84FD77B // _ZN3paf8PhXmItem10WidgetTypeEv															// paf::PhXmItem::WidgetType(void)
    // paf_A4438D60 // _ZN3paf8PhXmItem11AnimIconSetERKNS_12SurfaceRCPtrINS_7SurfaceEEES5_RK4vec4iiiS8_iiiii	// paf::PhXmItem::AnimIconSet(paf::SurfaceRCPtr<paf::Surface> const&, paf::SurfaceRCPtr<paf::Surface> const&, vec4 const&, int, int, int, vec4 const&, int, int, int, int, int)
    // paf_44E93267 // _ZN3paf8PhXmItem11PlayerStartEffRK4vec4													// paf::PhXmItem::PlayerStart(float, float, vec4 const&)
    // paf_DB9195CE // _ZN3paf8PhXmItem12AnimIconMoveERK4vec4ffiii												// paf::PhXmItem::AnimIconMove(vec4 const&, float, float, int, int, int)
    // paf_55921E70 // _ZN3paf8PhXmItem12AnimIconPlayEf															// paf::PhXmItem::AnimIconPlay(float)
    // paf_39D3A244 // _ZN3paf8PhXmItem12AnimIconStopEv															// paf::PhXmItem::AnimIconStop(void)
    // paf_CA784678 // _ZN3paf8PhXmItem12GetLineCountEi															// paf::PhXmItem::GetLineCount(int)
    // paf_FB7731FB // _ZN3paf8PhXmItem12ReleaseLabelEi															// paf::PhXmItem::ReleaseLabel(int)
    // paf_04081C1E // _ZN3paf8PhXmItem13SetLabelAlphaEfff														// paf::PhXmItem::SetLabelAlpha(float, float, float)
    // paf_C49D8C3E // _ZN3paf8PhXmItem16UpdateLabelColorEv														// paf::PhXmItem::UpdateLabelColor(void)
    // paf_54A7300E // _ZN3paf8PhXmItem5ClearEb																	// paf::PhXmItem::Clear(bool)
    // paf_925494CB // _ZN3paf8PhXmItem7FocusInEff																// paf::PhXmItem::FocusIn(float, float)
    // paf_3A50E116 // _ZN3paf8PhXmItem8BlinkEndEf																// paf::PhXmItem::BlinkEnd(float)
    // paf_19840447 // _ZN3paf8PhXmItem8FocusOutEff																// paf::PhXmItem::FocusOut(float, float)
    // paf_226FBD53 // _ZN3paf8PhXmItem8IconMoveERK4vec4ffiii													// paf::PhXmItem::IconMove(vec4 const&, float, float, int, int, int)
    // paf_34C6C205 // _ZN3paf8PhXmItem8IconSizeERK4vec4ffiii													// paf::PhXmItem::IconSize(vec4 const&, float, float, int, int, int)
    // paf_5F68B433 // _ZN3paf8PhXmItem9PlayerEndEff															// paf::PhXmItem::PlayerEnd(float, float)
    // paf_3441B471 // _ZN3paf8PhXmItemC1EPNS_8PhWidgetEPNS_8PhAppearE											// paf::PhXmItem::PhXmItem(paf::PhWidget *, paf::PhAppear *)

    // paf_BC8DD07D // _ZN3paf7PhXmBar10ScrollLeftEfPNS_7PhEventE	// paf::PhXmBar::ScrollLeft(float, paf::PhEvent *)
    // paf_703117AD // _ZN3paf7PhXmBar10WidgetTypeEv				// paf::PhXmBar::WidgetType(void)
    // paf_F744FE00 // _ZN3paf7PhXmBar11ScrollRightEfPNS_7PhEventE	// paf::PhXmBar::ScrollRight(float, paf::PhEvent *)
    // paf_534AC5C4 // _ZN3paf7PhXmBar11SetTopAlphaEfff				// paf::PhXmBar::SetTopAlpha(float, float, float)
    // paf_C1A00166 // _ZN3paf7PhXmBar13GetListWidgetEi				// paf::PhXmBar::GetListWidget(int)
    // paf_B24DE5AC // _ZN3paf7PhXmBar16SetOtherTopAlphaEfff		// paf::PhXmBar::SetOtherTopAlpha(float, float, float)
    // paf_5837B7E2 // _ZN3paf7PhXmBar16SetTopLabelAlphaEfff		// paf::PhXmBar::SetTopLabelAlpha(float, float, float)
    // paf_DDE862B5 // _ZN3paf7PhXmBar17SetOtherItemAlphaEfff		// paf::PhXmBar::SetOtherItemAlpha(float, float, float)
    // paf_6C8F62F7 // _ZN3paf7PhXmBar19GetFocusedItemIndexEi		// paf::PhXmBar::GetFocusedItemIndex(int)
    // paf_6A76DCEE // _ZN3paf7PhXmBar7SetFadeEfff					// paf::PhXmBar::SetFade(float, float, float)
    // paf_7BAAD6D1 // _ZN3paf7PhXmBar8HideFadeEff					// paf::PhXmBar::HideFade(float, float)
    // paf_85BAAAA8 // _ZN3paf7PhXmBar8IconMoveERK4vec4ffbiii		// paf::PhXmBar::IconMove(vec4 const&, float, float, bool, int, int, int)
    // paf_C94E8621 // _ZN3paf7PhXmBar8SelectInEfffi				// paf::PhXmBar::SelectIn(float, float, float, int)
    // paf_739C8C04 // _ZN3paf7PhXmBar8SetAlphaEfff					// paf::PhXmBar::SetAlpha(float, float, float)
    // paf_62ED555B // _ZN3paf7PhXmBar8ShowFadeEff					// paf::PhXmBar::ShowFade(float, float)
    // paf_EC7C4469 // _ZN3paf7PhXmBar9HideLabelEiff				// paf::PhXmBar::HideLabel(int, float, float)
    // paf_EB1BB57F // _ZN3paf7PhXmBar9SelectOutEf					// paf::PhXmBar::SelectOut(float)
    // paf_8846BC65 // _ZN3paf7PhXmBar9ShowLabelEiff				// paf::PhXmBar::ShowLabel(int, float, float)

    // paf_C5987EC3 // _ZN3paf8PhXmList10DeleteItemEif															// paf::PhXmList::DeleteItem(int, float)
    // paf_2D9D1687 // _ZN3paf8PhXmList10InsertItemEif															// paf::PhXmList::InsertItem(int, float)
    // paf_A166B23E // _ZN3paf8PhXmList10SetItemNumEi															// paf::PhXmList::SetItemNum(int)
    // paf_01059AF3 // _ZN3paf8PhXmList10SetKeyMaskEi															// paf::PhXmList::SetKeyMask(int)
    // paf_915890C7 // _ZN3paf8PhXmList10UpdateFormEf															// paf::PhXmList::UpdateForm(float)
    // paf_B35AAC2B // _ZN3paf8PhXmList10UpdateItemEi															// paf::PhXmList::UpdateItem(int)
    // paf_4FF7B8A9 // _ZN3paf8PhXmList10WidgetTypeEv															// paf::PhXmList::WidgetType(void)
    // paf_EA96A0D0 // _ZN3paf8PhXmList11AnimIconSetERKNS_12SurfaceRCPtrINS_7SurfaceEEES5_RK4vec4iiiS8_iiiii	// paf::PhXmList::AnimIconSet(paf::SurfaceRCPtr<paf::Surface> const&, paf::SurfaceRCPtr<paf::Surface> const&, vec4 const&, int, int, int, vec4 const&, int, int, int, int, int)
    // paf_80334194 // _ZN3paf8PhXmList11SetItemTypeEii															// paf::PhXmList::SetItemType(int, int)
    // paf_F35FE0BC // _ZN3paf8PhXmList11SetTopAlphaEfff														// paf::PhXmList::SetTopAlpha(float, float, float)
    // paf_9624DDC9 // _ZN3paf8PhXmList12SetItemAlphaEfff														// paf::PhXmList::SetItemAlpha(float, float, float)
    // paf_796A32FE // _ZN3paf8PhXmList13GetItemWidgetEi														// paf::PhXmList::GetItemWidget(int)
    // paf_FEDE9551 // _ZN3paf8PhXmList13SetArrowAlphaEfff														// paf::PhXmList::SetArrowAlpha(float, float, float)
    // paf_A74FFFC9 // _ZN3paf8PhXmList13SetLabelAlphaEfff														// paf::PhXmList::SetLabelAlpha(float, float, float)
    // paf_4DAEF6BE // _ZN3paf8PhXmList14ChangeListModeEii														// paf::PhXmList::ChangeListMode(int, int)
    // paf_B94B439F // _ZN3paf8PhXmList16SetTopLabelAlphaEfff													// paf::PhXmList::SetTopLabelAlpha(float, float, float)
    // paf_1B087988 // _ZN3paf8PhXmList16UpdateLabelColorEv														// paf::PhXmList::UpdateLabelColor(void)
    // paf_5D711BEE // _ZN3paf8PhXmList17SetFocusItemAlphaEfff													// paf::PhXmList::SetFocusItemAlpha(float, float, float)
    // paf_12F2B781 // _ZN3paf8PhXmList17SetOtherItemAlphaEfff													// paf::PhXmList::SetOtherItemAlpha(float, float, float)
    // paf_AC0EB3AB // _ZN3paf8PhXmList18SetFocusInTopColorERK4vec4ff											// paf::PhXmList::SetFocusInTopColor(vec4 const&, float, float)
    // paf_33A47C59 // _ZN3paf8PhXmList18SetOtherLabelAlphaEfff													// paf::PhXmList::SetOtherLabelAlpha(float, float, float)
    // paf_6E0347D4 // _ZN3paf8PhXmList18SetValueLabelAlphaEfff													// paf::PhXmList::SetValueLabelAlpha(float, float, float)
    // paf_A2C876E8 // _ZN3paf8PhXmList19SetFocusOutTopColorERK4vec4ff											// paf::PhXmList::SetFocusOutTopColor(vec4 const&, float, float)
    // paf_D005CC9F // _ZN3paf8PhXmList6RedrawEi																// paf::PhXmList::Redraw(int)
    // paf_DEF981C4 // _ZN3paf8PhXmList7FocusInEf																// paf::PhXmList::FocusIn(float)
    // paf_07047F37 // _ZN3paf8PhXmList8BlinkEndEf																// paf::PhXmList::BlinkEnd(float)
    // paf_814B3D90 // _ZN3paf8PhXmList8FocusOutEf																// paf::PhXmList::FocusOut(float)
    // paf_6964C72A // _ZN3paf8PhXmList8IconMoveEiRK4vec4ffbiii													// paf::PhXmList::IconMove(int, vec4 const&, float, float, bool, int, int, int)
    // paf_2689337F // _ZN3paf8PhXmList8IconSizeEiRK4vec4ffiii													// paf::PhXmList::IconSize(int, vec4 const&, float, float, int, int, int)
    // paf_459B404D // _ZN3paf8PhXmList9ArrowMoveERK4vec4ffi													// paf::PhXmList::ArrowMove(vec4 const&, float, float, int)
    // paf_27D4B92D // _ZN3paf8PhXmList9HideItemsEff															// paf::PhXmList::HideItems(float, float)
    // paf_BB12535D // _ZN3paf8PhXmList9SelectOutEf																// paf::PhXmList::SelectOut(float)
    // paf_14CF6448 // _ZN3paf8PhXmList9ShowItemsEff															// paf::PhXmList::ShowItems(float, float)

    CDECL_END

    class _vtable // it just works
    {
    public:
        struct _opd {
            uint32_t sub;
            uint32_t toc;
        };

        template<typename R, typename... Args>
        R CallMethod(int index, Args... args)
        {
            _opd** opd = reinterpret_cast<_opd**>(this);
            R(*fn)(Args...) = (R(*)(Args...))opd[index];
            return fn(args...);
        }
    };

    class Framework
    {
    public:
        class InitParam
        {
        public:
            InitParam() { paf_541F8EBB(this); }

        private:
            struct {                 // these value are set by paf_541F8EBB()
                uint32_t _dword_0x0; // = 0x40000;
                uint32_t _dword_0x4; // = 0x400000;
                uint32_t _dword_0x8; // = 0x200000;
                uint32_t _dword_0xC; // = 0;
                uint32_t _dword_0x10; // = 2002;
                uint32_t _dword_0x14; // = 0;
                uint32_t _dword_0x18; // = 0;
                uint32_t _dword_0x1C; // = 0;
                uint32_t _dword_0x20; // = 0;
                uint32_t _dword_0x24; // = 0;
                uint32_t _dword_0x28; // = 0;
                uint32_t _dword_0x2C; // = 0;
                uint32_t _dword_0x30; // = 0;
                uint32_t _dword_0x34; // = 0x200000;
                uint32_t _dword_0x38; // = 0x100000;
                uint32_t _dword_0x3C; // = 4;
                uint32_t _dword_0x40; // = 11;
                uint32_t _dword_0x44; // = 5;
                uint32_t _dword_0x48; // = 0x4000;
                uint32_t _dword_0x4C; // = 2003;
                uint32_t _dword_0x50; // = 491;
                uint32_t _dword_0x54; // = 0;
                uint32_t _dword_0x58; // = 0;
                uint32_t _dword_0x5C; // = 0;
                uint32_t _dword_0x60; // = 0;
                uint32_t __padding_0x64;
                uint32_t __padding_0x68;
                uint32_t __padding_0x6C;
                uint32_t __padding_0x70;
                uint32_t __padding_0x74;
                uint32_t __padding_0x78;
                uint32_t __padding_0x7C;
                uint32_t __padding_0x80;
                uint32_t __padding_0x84;
                uint32_t __padding_0x88;
                uint8_t _byte_0x8C; // = 1;
                uint8_t _byte_0x8D; // = 1;
                uint16_t __padding_0x8E;
                uint32_t _dword_0x90; // = -1;
                uint32_t _dword_0x94; // = -1;
                uint32_t _dword_0x98; // = -1;
                uint32_t _dword_0x9C; // = 0;
            } m_Data;
        };

    public:
        Framework(InitParam const& initParam)	{ paf_A5B4FB55(this, (void*)&initParam); }
        ~Framework()							{ paf_54E2C229(this); }

        static Framework& Instance() { return paf_AF58E756(); }

        int RequestShutdown()		{ return paf_1565FC46(this); }
        int Begin(float frameTime)	{ return paf_59BDA198(this, frameTime); }
        int Run(float frameTime)	{ return paf_85D1D23B(this, frameTime); }
        int End(float frameTime)	{ return paf_0EAA28B8(this, frameTime); }

    public:
        std::vector<View*> Plugins;
        char __padding_0x10[0x2C];
        bool bIsShutdownRequested;
    };

    class Surface
    {
    public:
        enum PageMode {
            // idk the real names, check is in paf_E81D263A()
            Mode1,
            Mode2
        };

    private:
        struct {
            char __padding_0x0[0x68];
        } m_Data;
    };

    template<class _Ty>
    class SurfaceRCPtr
    {
    public:
        _Ty* ptr;

        SurfaceRCPtr() : ptr(nullptr) {};
        SurfaceRCPtr(_Ty* p) : ptr(p) {};
        ~SurfaceRCPtr() {};
    };

    class View
    {
    public:
        static View* Find(char const* name) { 
            return paf_F21655F3(name); 

            /*
            // Tested and working, but using the export reduce memory usage
            Framework& g_Framework = Framework::Instance();
            for (auto it : g_Framework.Plugins)
                if (it->name == name)
                    return it;

            return nullptr;
            */
        }

        PhWidget* FindWidget(char const* widget)const { 
            return paf_794CEACB(this, widget); 
        }

        void PlaySound(char const* systemSound) { 
            paf_B93AFE7E(this, systemSound, 1.0, 0);
        }

        wchar_t* GetString(char const* localizedString)const { 
            return paf_89B67B9C(this, localizedString); 
        }

        SurfacePtr GetTexture(char const* texture)const {
            SurfacePtr texHandle = SurfacePtr();
            if (texture && texture[0])
                return paf_3A8454FC(texHandle, this, texture);
            return texHandle;
        }

        void CloseAll() {
            paf_202CA2A7(this);
        }

        template<typename R>
        R GetInterface(int interfaceId)const { 
            return (R)paf_23AFB290(this, interfaceId); 
        }

        void SetInterface(int interfaceId, void* interfaceStruct) { 
            paf_0A1DC401(this, interfaceId, interfaceStruct); 
        }

    public:
        int flags; // ?
        std::string name;
        std::string main;
        // ...
    };

    // untested, use at ur own risk
    class Module // used to load/unload modules and access their interface
    {
    public:
        Module(const char* path, sys_memory_container_t* memContainer = nullptr)	{ paf_CF068D31(this, path, 0, 0, memContainer); }
        ~Module()																	{ paf_2F5CEE6D(this); }

        template<typename R>
        R GetInterface(int interfaceId)const						{ return (R)paf_B9152E15(this, interfaceId); }
        void SetInterface(int interfaceId, void* interfaceStruct)	{ paf_3F7CB0BF(this, interfaceId, interfaceStruct); }

    private:
        struct {
            std::string path;
            char __padding_0x1C[0x14];
            int unknownParam;
        } *m_Data;
    };

    class PhEditText
    {
    public:
        class OskParam
        {
        public:
            OskParam()
            {
                paf_8C7A6C86(this);
            }

        public:
            struct {
                int dword_0x0; 
                int dword_0x4;
                int dword_0x8;
                char byte_0xC;
                int dword_0x10;
                const wchar_t* title; // 0x14
                int dword_0x18;
                int dword_0x1C;
                char byte_0x20;
                char byte_0x21;
                int dword_0x24;
                int dword_0x28;
                int pad[2];
            }; // size: 0x30? aint no way its bigger than dat
        };
    };

    class PhEvent
    {
    public:
        PhEvent(unsigned int r4, PhWidget* r5, unsigned int r6, int r7, int r8, int r9, int r10)	{ paf_C2F5EAF9(this, r4, r5, r6, r7, r8, r9, r10); }
        PhEvent(unsigned int r4, unsigned int r5, unsigned int r6, int r7, int r8, int r9, int r10) { paf_9C4C1564(this, r4, r5, r6, r7, r8, r9, r10); }

    private:
        struct {
            char __padding_0x0[0x28];
        } m_Data;
    };

    class PhHandler
    {
    public:
        enum Handler : int {
            PositionHandler = 0x1000001,
            ColorHandler = 0x1000002,
            SizeHandler = 0x1000004,
            ScaleHandler = 0x1000005,
            RotationHandler = 0x1000006
        };

    public:
        int DoCallBack(int callbackId, PhEvent* phEvent)											{ return paf_FE5A7950(this, callbackId, phEvent); }
        int HandlerProc(PhEvent* phEvent)															{ return paf_B60C4316(this, phEvent); }
        int KillTimerCB(int callbackId)																{ return paf_2CBA5A33(this, callbackId); }
        int SetCallBack(int callbackId, void(*callback)(PhWidget*, PhEvent*, void*), void* unknown) { return paf_986427A7(this, callbackId, callback, unknown); }
        int SetDeleteCB(void(*callback)(PhWidget*, PhEvent*, void*), void* unknown)					{ return paf_818162F2(this, callback, unknown); }
        int HandleFocusEvent(PhEvent* phEvent)														{ return paf_F7D65DC1(this, phEvent); }
        int HandlePointEvent(PhEvent* phEvent)														{ return paf_DBFE46EA(this, phEvent); }
        int HandleStateEvent(PhEvent* phEvent)														{ return paf_C051D361(this, phEvent); }
        int HandleSystemEvent(PhEvent* phEvent)														{ return paf_0C96D94F(this, phEvent); }
        int HandleCommandEvent(PhEvent* phEvent)													{ return paf_CE14748C(this, phEvent); }
        int HandleKeycodeEvent(PhEvent* phEvent)													{ return paf_A4D0FDCB(this, phEvent); }
        bool IsTimerCB(int callbackId)																{ return paf_4D0CAA13(this, callbackId); }

    private:
        struct {
            // idk...
        } m_Data;
    };

    class PhSText
    {
    public:
        enum Style : int {
            LineHeight = 0x28, // float
            LineSpacing = 0x2D // float
        };

    public:
        PhSText(PhSRender& r4, PhSRender* r5)	{ paf_66977993(this, r4, r5); }
        void Destroy()							{ paf_A6F56DD8(this); }
        bool IsReady()							{ return paf_561CBD17(this); }

        int RefreshText()						{ return paf_FF99F7AB(this); }
        int SetText(std::wstring const& text)	{ return paf_FBAF2957(this, text); }

        int SetLayoutStyle(int style, int value1, float value2)		{ return paf_6BE9B314(this, style, value1, value2); }
        int GetLayoutStyle(int style, int& value1, float& value2)	{ return paf_DD32A35C(this, style, value1, value2); }

        int SetStyle(int style, vec4 const& value)	{ return paf_638A0B38(this, style, value); }
        int SetStyle(int style, bool value)			{ return paf_8E3B155F(this, style, value); }
        int SetStyle(int style, float value)		{ return paf_165AD4A6(this, style, value); }
        int SetStyle(int style, int value)			{ return paf_983EA578(this, style, value); }
        int GetStyle(int style, vec4& value)		{ return paf_BE085CD4(this, style, value); }
        int GetStyle(int style, bool& value)		{ return paf_CBDF7130(this, style, value); }
        int GetStyle(int style, float& value)		{ return paf_F5116A56(this, style, value); }
        int GetStyle(int style, int& value)			{ return paf_D2DC1C89(this, style, value); }

    public:
        struct { // size: 0x260
            _vtable* vtable;
            char __padding_0x4[0x28];
            std::wstring text;
            char __padding_0x48[0x160];
            vec2 shadowPosition;
            vec2 scale;
            // ...
        } m_Data;
    };

    class PhWidget //: public PhHandler
    {
    public:
        enum Style : int {
            Anchor = 0x12, // int
            TextAlignment = 0x31, // int
            DrawTextShadow = 0x38 // bool, true by default
        };

        enum AnchorStyle : int {
            AnchorCenter,
            AnchorLeft = (1 << 0),
            AnchorRight = (1 << 1),
            AnchorTop = (1 << 4),
            AnchorBottom = (1 << 5)
        };

        enum TextAlignmentStyle : int {
            TextAlignCenter,
            TextAlignLeft = (1 << 0),
            TextAlignRight = (1 << 1)
        };

        class PhSRenderer // ? not sure about the name
        {
        public:
            struct { // size: ~0x40
                _vtable* vtable;
                char __padding_0x4[0x24];
                PhSText* sText;
                char __padding_0x2C[0x14];
            };
        };

    public:
        PhWidget& SetName(std::string const& name) {
            m_Data.name = name;
            return *this;
        }

        PhWidget& SetColor(vec4 color) {
            m_Data.colorScaleRGBA = color.clamp(0.0, 1.0);
            KillTimerCB(PhHandler::ColorHandler);
            return *this;
        }

        PhWidget& SetPosition(vec2 position) {
            SetLayoutPos(6, 5, 0, vec4(position.x, position.y, 0.0, 0.0));
            return *this;
        }

        PhWidget& SetSize(vec2 size) {
            SetLayoutSize(6, 5, 0, vec4(size.x, size.y, 0.0, 0.0));
            return *this;
        }

        PhWidget& SetRotation(float rollAngle, bool useRadian) {
            vec4 rotation = vec4(0.0, 0.0, rollAngle, 0.0);
            if (!useRadian)
                rotation *= 0.01745329251; //(3.1415926535897 / 180.0); // degree to radian

            SetRot_ontimer(rotation, nullptr, 0);
            KillTimerCB(PhHandler::RotationHandler);

            return *this;
        }

        std::string GetName() {
            return m_Data.name;
        }

        vec4 GetColor() {
            return m_Data.colorScaleRGBA;
        }

        bool IsAttached() {
            if (!m_Data.name.empty() && m_Data.parent)
                return m_Data.parent->FindChild(m_Data.name.c_str(), 0) != nullptr;

            return false;
        }

        bool ReorderChildren(PhWidget* child1, PhWidget* child2, int flag) {
            return paf_B5505299(this, child1, child2, flag);
        }

        PhWidget* FindChild(char const* name, int r5) { 
            return paf_D557F850(this, name, r5); 
        }

        void SetRot_ontimer(vec4 const& rotation, PhWidget* widgetTemplate, int r6) { 
            paf_67437488(this, rotation, widgetTemplate, r6); 
        }

        int KillTimerCB(int callbackId) { 
            return paf_2CBA5A33(reinterpret_cast<PhHandler const*>(this), callbackId); 
        }

        int SetCallBack(int callbackId, void(*callback)(PhWidget*, PhEvent*, void*), void* unknown) { 
            return paf_986427A7(reinterpret_cast<PhHandler const*>(this), callbackId, callback, unknown);
        }


        // da vtable, 81 functions (sub_* are from 4.84 dex vsh.self)
        bool IsInherit(char const* type)const	{ return m_Data.vtable->CallMethod<bool>(0, this, type); }
        char const* WidgetType()				{ return m_Data.vtable->CallMethod<char const*>(1, this); }

        void sub_3A6A68()		{ m_Data.vtable->CallMethod<void>(2, this); }
        void sub_3A6360()		{ m_Data.vtable->CallMethod<void>(3, this); }
        void DestroyWidget()	{ m_Data.vtable->CallMethod<void>(4, this); }
        int sub_3A0630()		{ return m_Data.vtable->CallMethod<int>(5, this); }

        int EventExec(PhEvent* phEvent)					{ return m_Data.vtable->CallMethod<int>(6, this, phEvent); }
        int HandlerProc(PhEvent* phEvent)				{ return m_Data.vtable->CallMethod<int>(7, this, phEvent); }
        int HandleKeycodeEvent(PhEvent* phEvent)		{ return m_Data.vtable->CallMethod<int>(8, this, phEvent); }
        int HandleAnalogEvent(PhEvent* phEvent)			{ return m_Data.vtable->CallMethod<int>(9, this, phEvent); }
        int HandlePointEvent(PhEvent* phEvent)			{ return m_Data.vtable->CallMethod<int>(10, this, phEvent); }
        int HandleFocusEvent(PhEvent* phEvent)			{ return m_Data.vtable->CallMethod<int>(11, this, phEvent); }
        int HandleFocusSwitchEvent(PhEvent* phEvent)	{ return m_Data.vtable->CallMethod<int>(12, this, phEvent); }
        int HandleFocusOutEvent(PhEvent* phEvent)		{ return m_Data.vtable->CallMethod<int>(13, this, phEvent); }
        int HandleFocusInEvent(PhEvent* phEvent)		{ return m_Data.vtable->CallMethod<int>(14, this, phEvent); }
        int HandleStateEvent(PhEvent* phEvent)			{ return m_Data.vtable->CallMethod<int>(15, this, phEvent); }
        int HandleCommandEvent(PhEvent* phEvent)		{ return m_Data.vtable->CallMethod<int>(16, this, phEvent); }
        int HandleSystemEvent(PhEvent* phEvent)			{ return m_Data.vtable->CallMethod<int>(17, this, phEvent); }

        PhWidget* GetParent()						{ return m_Data.vtable->CallMethod<PhWidget*>(18, this); }
        bool RemoveChild(int childIndex)			{ return m_Data.vtable->CallMethod<bool>(19, this, childIndex); }
        bool RemoveChild(PhWidget const* child)		{ return m_Data.vtable->CallMethod<bool>(20, this, child); }
        void RegistChild(PhWidget* child)			{ m_Data.vtable->CallMethod<void>(21, this, child); }

        bool SetLayoutPos(int layoutFactorX, int layoutFactorY, int layoutFactorZ, vec4 layoutPos)				{ return m_Data.vtable->CallMethod<int>(22, this, layoutFactorX, layoutFactorY, layoutFactorZ, layoutPos); }
        bool SetLayoutSize(int layoutFactorX, int layoutFactorY, int layoutFactorZ, vec4 layoutSize)			{ return m_Data.vtable->CallMethod<int>(23, this, layoutFactorX, layoutFactorY, layoutFactorZ, layoutSize); }
        void GetLayoutPos(int& layoutFactorX, int& layoutFactorY, int& layoutFactorZ, vec4& layoutPos)const		{ m_Data.vtable->CallMethod<void>(24, this, &layoutFactorX, &layoutFactorY, &layoutFactorZ, &layoutPos); }
        void GetLayoutSize(int& layoutFactorX, int& layoutFactorY, int& layoutFactorZ, vec4& layoutSize)const	{ m_Data.vtable->CallMethod<void>(25, this, &layoutFactorX, &layoutFactorY, &layoutFactorZ, &layoutSize); }
        bool UpdateLayoutPos()																					{ return m_Data.vtable->CallMethod<bool>(26, this); }
        bool UpdateLayoutSize()																					{ return m_Data.vtable->CallMethod<bool>(27, this); }
        bool UpdateLayoutStyle(int r4)																			{ return m_Data.vtable->CallMethod<bool>(28, this); }
        void UpdateLayout(bool updateChilds) /* not sure about the argument */									{ m_Data.vtable->CallMethod<void>(29, this, updateChilds); }
        PhWidget* GetLayoutPosValue() /* return 'this'? */														{ return m_Data.vtable->CallMethod<PhWidget*>(30, this); }
        PhWidget* GetLayoutSizeValue() /* return 'this'? */														{ return m_Data.vtable->CallMethod<PhWidget*>(31, this); }

        void ClearColor() /* not sure */								{ m_Data.vtable->CallMethod<void>(32, this); }
        void SetMetaAlpha_ontimer(float metaAlpha, bool applyToChilds)	{ m_Data.vtable->CallMethod<void>(33, this, metaAlpha, applyToChilds); }
        void sub_3A0660(float f1) /* write f1 at 0x110 */				{ m_Data.vtable->CallMethod<void>(34, this, f1); }
        void sub_3A0668(float f1) /* write f1 at 0x114 */				{ m_Data.vtable->CallMethod<void>(35, this, f1); }

        void SetSize_ontimer(vec4 const& size)							{ m_Data.vtable->CallMethod<void>(36, this, &size); }
        int UpdateState()												{ return m_Data.vtable->CallMethod<int>(37, this); }
        void DrawThis(unsigned int r4 = 0xffffffff, bool r5 = false)	{ m_Data.vtable->CallMethod<void>(38, this, r4, r5); }
        int sub_3A0670(int r4)											{ return m_Data.vtable->CallMethod<int>(39, this, r4); }
        int paf_6458160F(int r4, int r5, int r6, int r7)				{ return m_Data.vtable->CallMethod<int>(40, this, r4, r5, r6, r7); }

        int SetStyle(int style, bool value)					{ return m_Data.vtable->CallMethod<int>(41, this, style, value); }
        int SetStyle(int style, int value)					{ return m_Data.vtable->CallMethod<int>(42, this, style, value); }
        int SetStyle(int style, float value)				{ return m_Data.vtable->CallMethod<int>(43, this, style, value); }
        int SetStyle(int style, vec4 const& value)			{ return m_Data.vtable->CallMethod<int>(44, this, style, &value); }
        int SetStyle(int style, int r5, bool value)			{ return m_Data.vtable->CallMethod<int>(45, this, style, r5, value); }
        int SetStyle(int style, int r5, int value)			{ return m_Data.vtable->CallMethod<int>(46, this, style, r5, value); }
        int SetStyle(int style, int r5, float value)		{ return m_Data.vtable->CallMethod<int>(47, this, style, r5, value); }
        int SetStyle(int style, int r5, vec4 const& value)	{ return m_Data.vtable->CallMethod<int>(48, this, style, r5, value); }
        int GetStyle(int style, bool& value)				{ return m_Data.vtable->CallMethod<int>(49, this, style, &value); }
        int GetStyle(int style, int& value)					{ return m_Data.vtable->CallMethod<int>(50, this, style, &value); }
        int GetStyle(int style, float& value)				{ return m_Data.vtable->CallMethod<int>(51, this, style, &value); }
        int GetStyle(int style, vec4& value)				{ return m_Data.vtable->CallMethod<int>(52, this, style, &value); }
        int GetStyle(int style, float* matrix4)				{ return m_Data.vtable->CallMethod<int>(53, this, style, matrix4); }
        int GetStyle(int style, int r5, bool& value)		{ return m_Data.vtable->CallMethod<int>(54, this, style, r5, &value); }
        int GetStyle(int style, int r5, int& value)			{ return m_Data.vtable->CallMethod<int>(55, this, style, r5, &value); }
        int GetStyle(int style, int r5, float& value)		{ return m_Data.vtable->CallMethod<int>(56, this, style, r5, &value); }
        int GetStyle(int style, int r5, vec4& value)		{ return m_Data.vtable->CallMethod<int>(57, this, style, r5, &value); }
        int GetStyle(int style, int r5, mat4& matrix4)		{ return m_Data.vtable->CallMethod<int>(58, this, style, r5, &matrix4); }

        int SetLayoutStyle(int style, int r5, float value)								{ return m_Data.vtable->CallMethod<int>(59, this, style, r5, value); }
        int SetLayoutStyle(int style, int r5, int r6, int r7, vec4 value)				{ return m_Data.vtable->CallMethod<int>(60, this, style, r5, r6, r7, value); }
        int SetLayoutStyle(int style, int r5, int r6, float value)						{ return m_Data.vtable->CallMethod<int>(61, this, style, r5, r6, value); }
        int SetLayoutStyle(int style, int r5, int r6, int r7, int r8, vec4 value)		{ return m_Data.vtable->CallMethod<int>(62, this, style, r5, r6, r7, r8, value); }
        int GetLayoutStyle(int style, int& r5, float& value)							{ return m_Data.vtable->CallMethod<int>(63, this, style, &r5, &value); }
        int GetLayoutStyle(int style, int& r5, int& r6, int& r7, vec4& value)			{ return m_Data.vtable->CallMethod<int>(64, this, style, &r5, &r6, &r7, &value); }
        int GetLayoutStyle(int style, int r5, int& r6, float& value)					{ return m_Data.vtable->CallMethod<int>(65, this, style, r5, &r6, &value); }
        int GetLayoutStyle(int style, int r5, int& r6, int& r7, int& r8, vec4& value)	{ return m_Data.vtable->CallMethod<int>(66, this, style, r5, &r6, &r7, &r8, &value); }

        int paf_ADE746B6(int r4, int r5)						{ return m_Data.vtable->CallMethod<int>(67, this, r4, r5); }
        int SetTexture(SurfacePtr const& texture, int r5 = 0)	{ return m_Data.vtable->CallMethod<int>(68, this, &texture, r5); }
        int GetTexture(SurfacePtr& texture, int r5 = 0)const	{ return m_Data.vtable->CallMethod<int>(69, this, &texture, r5); } // le funny number

        int SetText(std::wstring const& text, int r5 = 0)					{ return m_Data.vtable->CallMethod<int>(70, this, &text, r5); }
        int GetText(std::wstring& text, int r5 = 0)const					{ return m_Data.vtable->CallMethod<int>(71, this, &text, r5); }
        int BeginEditText(PhEditText::OskParam& oskParam, int r5)			{ return m_Data.vtable->CallMethod<int>(72, this, &oskParam, r5); }
        int EndEditText()													{ return m_Data.vtable->CallMethod<int>(73, this); }
        int GetEditTextPart(int& part)const									{ return m_Data.vtable->CallMethod<int>(74, this, &part); }

        void paf_12CACB14()																		{ m_Data.vtable->CallMethod<void>(75, this); }
        int SetFocus(PhEvent* phEvent, unsigned int r5)											{ return m_Data.vtable->CallMethod<int>(76, this, phEvent, r5); }
        int ReleaseFocus(bool r4)																{ return m_Data.vtable->CallMethod<int>(77, this, r4); }
        int SetDispatch(unsigned int r4)														{ return m_Data.vtable->CallMethod<int>(78, this, r4); }
        int paf_4F635131(int r4, int r5, int r6, int r7, float f1, float f2)					{ return m_Data.vtable->CallMethod<int>(79, this, r4, r5, r6, r7, f1, f2); }
        int paf_A9864A6D(int r4, int r5, int r6, int r7, int r8, float f1, int r10, float f2)	{ return m_Data.vtable->CallMethod<int>(80, this, r4, r5, r6, r7, r8, f1, r10, f2); }

    public:
        struct { // size: 0x290
            _vtable* vtable;
            std::string name;
            char __padding_0x20[0xC0];
            // PhScene 0xDC
            PhWidget* parent;
            char __padding_0xE4[0xC];
            PhSRenderer* renderer;
            char __padding_0xF4[0x18];
            float metaAlpha;
            char __padding_0x110[0x10];
            vec4 colorScaleRGBA;
            vec4 positionOnTimer;
            vec4 scaleOnTimer;
            vec4 rotationOnTimer;
            char __padding_0x160[0x4C];
            float verticalItalicAmount;
            float scaleY;
            char __padding_0x1B4[0xC];
            float horizontalItalicAmount;
            float scaleX;
            char __padding_0x1C8[0x18];
            vec4 position;
            char __padding_0x1F0[0x40];
            vec4 sizeOnTimer;
            char __padding_0x240[0x10];
            int positionLayoutFactorX;
            int positionLayoutFactorY;
            int positionLayoutFactorZ;
            vec4 positionLayout;
            int sizeLayoutFactorX;
            int sizeLayoutFactorY;
            int sizeLayoutFactorZ;
            vec4 sizeLayout;
            char __padding_0x288[0x8];
        } m_Data;
    };

    class PhPlane : public PhWidget
    {
    public:
        PhPlane(PhWidget* parent, void* phAppear = nullptr) { paf_D0197A7D(this, parent, phAppear); }
        ~PhPlane()											{ if (IsAttached()) paf_0C16A258(this); }
    };

    class PhText : public PhWidget
    {
    public:
        PhText(PhWidget* parent, void* phAppear = nullptr)	{ paf_7F0930C6(this, parent, phAppear); }
        ~PhText()											{ if (IsAttached()) paf_738BAAC0(this); }

        PhText& RefreshText() {
            m_Data.renderer->sText->RefreshText();
            return *this;
        }

        PhText& SetTextHeight(float height) {
            m_Data.renderer->sText->SetStyle(PhSText::LineHeight, height);
            return *this;
        }

        float GetTextHeight() {
            float height = 0.0;
            m_Data.renderer->sText->GetStyle(PhSText::LineHeight, height);
            return height;
        }

    private:
        char __padding_0x290[0x14];
    };
}


#endif // __PAF_HPP__