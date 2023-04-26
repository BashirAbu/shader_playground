#pragma once

#ifdef SPG_WINDOWS
#include <Windows.h>
#include <gl/GL.h>
#endif
#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#define GL_DEPTH_BUFFER_BIT                       0x00000100
#define GL_STENCIL_BUFFER_BIT                     0x00000400
#define GL_COLOR_BUFFER_BIT                       0x00004000
#define GL_FALSE                                  0
#define GL_TRUE                                   1
#define GL_POINTS                                 0x0000
#define GL_LINES                                  0x0001
#define GL_LINE_LOOP                              0x0002
#define GL_LINE_STRIP                             0x0003
#define GL_TRIANGLES                              0x0004
#define GL_TRIANGLE_STRIP                         0x0005
#define GL_TRIANGLE_FAN                           0x0006
#define GL_QUADS                                  0x0007
#define GL_NEVER                                  0x0200
#define GL_LESS                                   0x0201
#define GL_EQUAL                                  0x0202
#define GL_LEQUAL                                 0x0203
#define GL_GREATER                                0x0204
#define GL_NOTEQUAL                               0x0205
#define GL_GEQUAL                                 0x0206
#define GL_ALWAYS                                 0x0207
#define GL_ZERO                                   0
#define GL_ONE                                    1
#define GL_SRC_COLOR                              0x0300
#define GL_ONE_MINUS_SRC_COLOR                    0x0301
#define GL_SRC_ALPHA                              0x0302
#define GL_ONE_MINUS_SRC_ALPHA                    0x0303
#define GL_DST_ALPHA                              0x0304
#define GL_ONE_MINUS_DST_ALPHA                    0x0305
#define GL_DST_COLOR                              0x0306
#define GL_ONE_MINUS_DST_COLOR                    0x0307
#define GL_SRC_ALPHA_SATURATE                     0x0308
#define GL_NONE                                   0
#define GL_FRONT_LEFT                             0x0400
#define GL_FRONT_RIGHT                            0x0401
#define GL_BACK_LEFT                              0x0402
#define GL_BACK_RIGHT                             0x0403
#define GL_FRONT                                  0x0404
#define GL_BACK                                   0x0405
#define GL_LEFT                                   0x0406
#define GL_RIGHT                                  0x0407
#define GL_FRONT_AND_BACK                         0x0408
#define GL_NO_ERROR                               0
#define GL_INVALID_ENUM                           0x0500
#define GL_INVALID_VALUE                          0x0501
#define GL_INVALID_OPERATION                      0x0502
#define GL_OUT_OF_MEMORY                          0x0505
#define GL_CW                                     0x0900
#define GL_CCW                                    0x0901
#define GL_POINT_SIZE                             0x0B11
#define GL_POINT_SIZE_RANGE                       0x0B12
#define GL_POINT_SIZE_GRANULARITY                 0x0B13
#define GL_LINE_SMOOTH                            0x0B20
#define GL_LINE_WIDTH                             0x0B21
#define GL_LINE_WIDTH_RANGE                       0x0B22
#define GL_LINE_WIDTH_GRANULARITY                 0x0B23
#define GL_POLYGON_MODE                           0x0B40
#define GL_POLYGON_SMOOTH                         0x0B41
#define GL_CULL_FACE                              0x0B44
#define GL_CULL_FACE_MODE                         0x0B45
#define GL_FRONT_FACE                             0x0B46
#define GL_DEPTH_RANGE                            0x0B70
#define GL_DEPTH_TEST                             0x0B71
#define GL_DEPTH_WRITEMASK                        0x0B72
#define GL_DEPTH_CLEAR_VALUE                      0x0B73
#define GL_DEPTH_FUNC                             0x0B74
#define GL_STENCIL_TEST                           0x0B90
#define GL_STENCIL_CLEAR_VALUE                    0x0B91
#define GL_STENCIL_FUNC                           0x0B92
#define GL_STENCIL_VALUE_MASK                     0x0B93
#define GL_STENCIL_FAIL                           0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL                0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS                0x0B96
#define GL_STENCIL_REF                            0x0B97
#define GL_STENCIL_WRITEMASK                      0x0B98
#define GL_VIEWPORT                               0x0BA2
#define GL_DITHER                                 0x0BD0
#define GL_BLEND_DST                              0x0BE0
#define GL_BLEND_SRC                              0x0BE1
#define GL_BLEND                                  0x0BE2
#define GL_LOGIC_OP_MODE                          0x0BF0
#define GL_DRAW_BUFFER                            0x0C01
#define GL_READ_BUFFER                            0x0C02
#define GL_SCISSOR_BOX                            0x0C10
#define GL_SCISSOR_TEST                           0x0C11
#define GL_COLOR_CLEAR_VALUE                      0x0C22
#define GL_COLOR_WRITEMASK                        0x0C23
#define GL_DOUBLEBUFFER                           0x0C32
#define GL_STEREO                                 0x0C33
#define GL_LINE_SMOOTH_HINT                       0x0C52
#define GL_POLYGON_SMOOTH_HINT                    0x0C53
#define GL_UNPACK_SWAP_BYTES                      0x0CF0
#define GL_UNPACK_LSB_FIRST                       0x0CF1
#define GL_UNPACK_ROW_LENGTH                      0x0CF2
#define GL_UNPACK_SKIP_ROWS                       0x0CF3
#define GL_UNPACK_SKIP_PIXELS                     0x0CF4
#define GL_UNPACK_ALIGNMENT                       0x0CF5
#define GL_PACK_SWAP_BYTES                        0x0D00
#define GL_PACK_LSB_FIRST                         0x0D01
#define GL_PACK_ROW_LENGTH                        0x0D02
#define GL_PACK_SKIP_ROWS                         0x0D03
#define GL_PACK_SKIP_PIXELS                       0x0D04
#define GL_PACK_ALIGNMENT                         0x0D05
#define GL_MAX_TEXTURE_SIZE                       0x0D33
#define GL_MAX_VIEWPORT_DIMS                      0x0D3A
#define GL_SUBPIXEL_BITS                          0x0D50
#define GL_TEXTURE_1D                             0x0DE0
#define GL_TEXTURE_2D                             0x0DE1
#define GL_TEXTURE_WIDTH                          0x1000
#define GL_TEXTURE_HEIGHT                         0x1001
#define GL_TEXTURE_BORDER_COLOR                   0x1004
#define GL_DONT_CARE                              0x1100
#define GL_FASTEST                                0x1101
#define GL_NICEST                                 0x1102
#define GL_BYTE                                   0x1400
#define GL_UNSIGNED_BYTE                          0x1401
#define GL_SHORT                                  0x1402
#define GL_UNSIGNED_SHORT                         0x1403
#define GL_INT                                    0x1404
#define GL_UNSIGNED_INT                           0x1405
#define GL_FLOAT                                  0x1406
#define GL_STACK_OVERFLOW                         0x0503
#define GL_STACK_UNDERFLOW                        0x0504
#define GL_CLEAR                                  0x1500
#define GL_AND                                    0x1501
#define GL_AND_REVERSE                            0x1502
#define GL_COPY                                   0x1503
#define GL_AND_INVERTED                           0x1504
#define GL_NOOP                                   0x1505
#define GL_XOR                                    0x1506
#define GL_OR                                     0x1507
#define GL_NOR                                    0x1508
#define GL_EQUIV                                  0x1509
#define GL_INVERT                                 0x150A
#define GL_OR_REVERSE                             0x150B
#define GL_COPY_INVERTED                          0x150C
#define GL_OR_INVERTED                            0x150D
#define GL_NAND                                   0x150E
#define GL_SET                                    0x150F
#define GL_TEXTURE                                0x1702
#define GL_COLOR                                  0x1800
#define GL_DEPTH                                  0x1801
#define GL_STENCIL                                0x1802
#define GL_STENCIL_INDEX                          0x1901
#define GL_DEPTH_COMPONENT                        0x1902
#define GL_RED                                    0x1903
#define GL_GREEN                                  0x1904
#define GL_BLUE                                   0x1905
#define GL_ALPHA                                  0x1906
#define GL_RGB                                    0x1907
#define GL_RGBA                                   0x1908
#define GL_POINT                                  0x1B00
#define GL_LINE                                   0x1B01
#define GL_FILL                                   0x1B02
#define GL_KEEP                                   0x1E00
#define GL_REPLACE                                0x1E01
#define GL_INCR                                   0x1E02
#define GL_DECR                                   0x1E03
#define GL_VENDOR                                 0x1F00
#define GL_RENDERER                               0x1F01
#define GL_VERSION                                0x1F02
#define GL_EXTENSIONS                             0x1F03
#define GL_NEAREST                                0x2600
#define GL_LINEAR                                 0x2601
#define GL_NEAREST_MIPMAP_NEAREST                 0x2700
#define GL_LINEAR_MIPMAP_NEAREST                  0x2701
#define GL_NEAREST_MIPMAP_LINEAR                  0x2702
#define GL_LINEAR_MIPMAP_LINEAR                   0x2703
#define GL_TEXTURE_MAG_FILTER                     0x2800
#define GL_TEXTURE_MIN_FILTER                     0x2801
#define GL_TEXTURE_WRAP_S                         0x2802
#define GL_TEXTURE_WRAP_T                         0x2803
#define GL_REPEAT                                 0x2901

#define GL_DEBUG_OUTPUT_SYNCHRONOUS               0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH       0x8243
#define GL_DEBUG_CALLBACK_FUNCTION                0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM              0x8245
#define GL_DEBUG_SOURCE_API                       0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM             0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER           0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY               0x8249
#define GL_DEBUG_SOURCE_APPLICATION               0x824A
#define GL_DEBUG_SOURCE_OTHER                     0x824B
#define GL_DEBUG_TYPE_ERROR                       0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR         0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR          0x824E
#define GL_DEBUG_TYPE_PORTABILITY                 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE                 0x8250
#define GL_DEBUG_TYPE_OTHER                       0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH               0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES              0x9144
#define GL_DEBUG_LOGGED_MESSAGES                  0x9145
#define GL_DEBUG_SEVERITY_HIGH                    0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                  0x9147
#define GL_DEBUG_SEVERITY_LOW                     0x9148
#define GL_DEBUG_TYPE_MARKER                      0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                  0x8269
#define GL_DEBUG_TYPE_POP_GROUP                   0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION            0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH            0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH                0x826D
#define GL_DEBUG_OUTPUT		                      0x92e0

#define GL_MAJOR_VERSION                          0x821B
#define	GL_MINOR_VERSION                          0x821C
#define	GL_NUM_EXTENSIONS                         0x821D
#define	GL_CONTEXT_FLAGS                          0x821E
#define GL_CONTEXT_FLAG_DEBUG_BIT                 0x00000002

#define GL_BUFFER_SIZE                            0x8764
#define GL_BUFFER_USAGE                           0x8765
#define GL_QUERY_COUNTER_BITS                     0x8864
#define GL_CURRENT_QUERY                          0x8865
#define GL_QUERY_RESULT                           0x8866
#define GL_QUERY_RESULT_AVAILABLE                 0x8867
#define GL_ARRAY_BUFFER                           0x8892
#define GL_ELEMENT_ARRAY_BUFFER                   0x8893
#define GL_ARRAY_BUFFER_BINDING                   0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING           0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING     0x889F
#define GL_READ_ONLY                              0x88B8
#define GL_WRITE_ONLY                             0x88B9
#define GL_READ_WRITE                             0x88BA
#define GL_BUFFER_ACCESS                          0x88BB
#define GL_BUFFER_MAPPED                          0x88BC
#define GL_BUFFER_MAP_POINTER                     0x88BD
#define GL_STREAM_DRAW                            0x88E0
#define GL_STREAM_READ                            0x88E1
#define GL_STREAM_COPY                            0x88E2
#define GL_STATIC_DRAW                            0x88E4
#define GL_STATIC_READ                            0x88E5
#define GL_STATIC_COPY                            0x88E6
#define GL_DYNAMIC_DRAW                           0x88E8
#define GL_DYNAMIC_READ                           0x88E9
#define GL_DYNAMIC_COPY                           0x88EA
#define GL_SAMPLES_PASSED                         0x8914
#define GL_SRC1_ALPHA                             0x8589

#define GL_FIXED                                  0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE         0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT       0x8B9B
#define GL_LOW_FLOAT                              0x8DF0
#define GL_MEDIUM_FLOAT                           0x8DF1
#define GL_HIGH_FLOAT                             0x8DF2
#define GL_LOW_INT                                0x8DF3
#define GL_MEDIUM_INT                             0x8DF4
#define GL_HIGH_INT                               0x8DF5
#define GL_SHADER_COMPILER                        0x8DFA
#define GL_SHADER_BINARY_FORMATS                  0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS              0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS             0x8DFB
#define GL_MAX_VARYING_VECTORS                    0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS           0x8DFD
#define GL_RGB565                                 0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT        0x8257
#define GL_PROGRAM_BINARY_LENGTH                  0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS             0x87FE
#define GL_PROGRAM_BINARY_FORMATS                 0x87FF
#define GL_VERTEX_SHADER_BIT                      0x00000001
#define GL_FRAGMENT_SHADER_BIT                    0x00000002
#define GL_GEOMETRY_SHADER_BIT                    0x00000004
#define GL_TESS_CONTROL_SHADER_BIT                0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT             0x00000010
#define GL_ALL_SHADER_BITS                        0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE                      0x8258
#define GL_ACTIVE_PROGRAM                         0x8259
#define GL_PROGRAM_PIPELINE_BINDING               0x825A
#define GL_MAX_VIEWPORTS                          0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS                 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE                  0x825D
#define GL_LAYER_PROVOKING_VERTEX                 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX        0x825F
#define GL_UNDEFINED_VERTEX                       0x8260

#define GL_SHADER_BINARY_FORMAT_SPIR_V            0x9551
#define GL_SPIR_V_BINARY                          0x9552
#define GL_PARAMETER_BUFFER                       0x80EE
#define GL_PARAMETER_BUFFER_BINDING               0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT              0x00000008
#define GL_VERTICES_SUBMITTED                     0x82EE
#define GL_PRIMITIVES_SUBMITTED                   0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS              0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES            0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS     0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED     0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS            0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS             0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES              0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES             0x82F7
#define GL_POLYGON_OFFSET_CLAMP                   0x8E1B
#define GL_SPIR_V_EXTENSIONS                      0x9553
#define GL_NUM_SPIR_V_EXTENSIONS                  0x9554
#define GL_TEXTURE_MAX_ANISOTROPY                 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY             0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW            0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW     0x82ED

#define GL_BLEND_EQUATION_RGB                     0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED            0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE               0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE             0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE               0x8625
#define GL_CURRENT_VERTEX_ATTRIB                  0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE              0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER            0x8645
#define GL_STENCIL_BACK_FUNC                      0x8800
#define GL_STENCIL_BACK_FAIL                      0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL           0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS           0x8803
#define GL_MAX_DRAW_BUFFERS                       0x8824
#define GL_DRAW_BUFFER0                           0x8825
#define GL_DRAW_BUFFER1                           0x8826
#define GL_DRAW_BUFFER2                           0x8827
#define GL_DRAW_BUFFER3                           0x8828
#define GL_DRAW_BUFFER4                           0x8829
#define GL_DRAW_BUFFER5                           0x882A
#define GL_DRAW_BUFFER6                           0x882B
#define GL_DRAW_BUFFER7                           0x882C
#define GL_DRAW_BUFFER8                           0x882D
#define GL_DRAW_BUFFER9                           0x882E
#define GL_DRAW_BUFFER10                          0x882F
#define GL_DRAW_BUFFER11                          0x8830
#define GL_DRAW_BUFFER12                          0x8831
#define GL_DRAW_BUFFER13                          0x8832
#define GL_DRAW_BUFFER14                          0x8833
#define GL_DRAW_BUFFER15                          0x8834
#define GL_BLEND_EQUATION_ALPHA                   0x883D
#define GL_MAX_VERTEX_ATTRIBS                     0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED         0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS                0x8872
#define GL_FRAGMENT_SHADER                        0x8B30
#define GL_VERTEX_SHADER                          0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS        0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS          0x8B4A
#define GL_MAX_VARYING_FLOATS                     0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS         0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS       0x8B4D
#define GL_SHADER_TYPE                            0x8B4F
#define GL_FLOAT_VEC2                             0x8B50
#define GL_FLOAT_VEC3                             0x8B51
#define GL_FLOAT_VEC4                             0x8B52
#define GL_INT_VEC2                               0x8B53
#define GL_INT_VEC3                               0x8B54
#define GL_INT_VEC4                               0x8B55
#define GL_BOOL                                   0x8B56
#define GL_BOOL_VEC2                              0x8B57
#define GL_BOOL_VEC3                              0x8B58
#define GL_BOOL_VEC4                              0x8B59
#define GL_FLOAT_MAT2                             0x8B5A
#define GL_FLOAT_MAT3                             0x8B5B
#define GL_FLOAT_MAT4                             0x8B5C
#define GL_SAMPLER_1D                             0x8B5D
#define GL_SAMPLER_2D                             0x8B5E
#define GL_SAMPLER_3D                             0x8B5F
#define GL_SAMPLER_CUBE                           0x8B60
#define GL_SAMPLER_1D_SHADOW                      0x8B61
#define GL_SAMPLER_2D_SHADOW                      0x8B62
#define GL_DELETE_STATUS                          0x8B80
#define GL_COMPILE_STATUS                         0x8B81
#define GL_LINK_STATUS                            0x8B82
#define GL_VALIDATE_STATUS                        0x8B83
#define GL_INFO_LOG_LENGTH                        0x8B84
#define GL_ATTACHED_SHADERS                       0x8B85
#define GL_ACTIVE_UNIFORMS                        0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH              0x8B87
#define GL_SHADER_SOURCE_LENGTH                   0x8B88
#define GL_ACTIVE_ATTRIBUTES                      0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH            0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT        0x8B8B
#define GL_SHADING_LANGUAGE_VERSION               0x8B8C
#define GL_CURRENT_PROGRAM                        0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN              0x8CA0
#define GL_LOWER_LEFT                             0x8CA1
#define GL_UPPER_LEFT                             0x8CA2
#define GL_STENCIL_BACK_REF                       0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                 0x8CA5

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                               0x84C0
#define GL_TEXTURE1                               0x84C1
#define GL_TEXTURE2                               0x84C2
#define GL_TEXTURE3                               0x84C3
#define GL_TEXTURE4                               0x84C4
#define GL_TEXTURE5                               0x84C5
#define GL_TEXTURE6                               0x84C6
#define GL_TEXTURE7                               0x84C7
#define GL_TEXTURE8                               0x84C8
#define GL_TEXTURE9                               0x84C9
#define GL_TEXTURE10                              0x84CA
#define GL_TEXTURE11                              0x84CB
#define GL_TEXTURE12                              0x84CC
#define GL_TEXTURE13                              0x84CD
#define GL_TEXTURE14                              0x84CE
#define GL_TEXTURE15                              0x84CF
#define GL_TEXTURE16                              0x84D0
#define GL_TEXTURE17                              0x84D1
#define GL_TEXTURE18                              0x84D2
#define GL_TEXTURE19                              0x84D3
#define GL_TEXTURE20                              0x84D4
#define GL_TEXTURE21                              0x84D5
#define GL_TEXTURE22                              0x84D6
#define GL_TEXTURE23                              0x84D7
#define GL_TEXTURE24                              0x84D8
#define GL_TEXTURE25                              0x84D9
#define GL_TEXTURE26                              0x84DA
#define GL_TEXTURE27                              0x84DB
#define GL_TEXTURE28                              0x84DC
#define GL_TEXTURE29                              0x84DD
#define GL_TEXTURE30                              0x84DE
#define GL_TEXTURE31                              0x84DF
#define GL_ACTIVE_TEXTURE                         0x84E0
#define GL_MULTISAMPLE                            0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE               0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                    0x809F
#define GL_SAMPLE_COVERAGE                        0x80A0
#define GL_SAMPLE_BUFFERS                         0x80A8
#define GL_SAMPLES                                0x80A9
#define GL_SAMPLE_COVERAGE_VALUE                  0x80AA
#define GL_SAMPLE_COVERAGE_INVERT                 0x80AB
#define GL_TEXTURE_CUBE_MAP                       0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP               0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X            0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X            0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y            0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y            0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z            0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z            0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP                 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE              0x851C
#define GL_COMPRESSED_RGB                         0x84ED
#define GL_COMPRESSED_RGBA                        0x84EE
#define GL_TEXTURE_COMPRESSION_HINT               0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE          0x86A0
#define GL_TEXTURE_COMPRESSED                     0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS         0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS             0x86A3
#define GL_CLAMP_TO_BORDER                        0x812D
#define GL_COMPARE_REF_TO_TEXTURE                 0x884E
#define GL_CLIP_DISTANCE0                         0x3000
#define GL_CLIP_DISTANCE1                         0x3001
#define GL_CLIP_DISTANCE2                         0x3002
#define GL_CLIP_DISTANCE3                         0x3003
#define GL_CLIP_DISTANCE4                         0x3004
#define GL_CLIP_DISTANCE5                         0x3005
#define GL_CLIP_DISTANCE6                         0x3006
#define GL_CLIP_DISTANCE7                         0x3007
#define GL_MAX_CLIP_DISTANCES                     0x0D32
#define GL_MAJOR_VERSION                          0x821B
#define GL_MINOR_VERSION                          0x821C
#define GL_NUM_EXTENSIONS                         0x821D
#define GL_CONTEXT_FLAGS                          0x821E
#define GL_COMPRESSED_RED                         0x8225
#define GL_COMPRESSED_RG                          0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT    0x00000001
#define GL_RGBA32F                                0x8814
#define GL_RGB32F                                 0x8815
#define GL_RGBA16F                                0x881A
#define GL_RGB16F                                 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER            0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS               0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET               0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET               0x8905
#define GL_CLAMP_READ_COLOR                       0x891C
#define GL_FIXED_ONLY                             0x891D
#define GL_MAX_VARYING_COMPONENTS                 0x8B4B
#define GL_TEXTURE_1D_ARRAY                       0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY                 0x8C19
#define GL_TEXTURE_2D_ARRAY                       0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY                 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY               0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY               0x8C1D
#define GL_R11F_G11F_B10F                         0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV           0x8C3B
#define GL_RGB9_E5                                0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV               0x8C3E
#define GL_TEXTURE_SHARED_SIZE                    0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH  0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE         0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS            0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START        0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE         0x8C85
#define GL_PRIMITIVES_GENERATED                   0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN  0x8C88
#define GL_RASTERIZER_DISCARD                     0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS                    0x8C8C
#define GL_SEPARATE_ATTRIBS                       0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER              0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING      0x8C8F
#define GL_RGBA32UI                               0x8D70
#define GL_RGB32UI                                0x8D71
#define GL_RGBA16UI                               0x8D76
#define GL_RGB16UI                                0x8D77
#define GL_RGBA8UI                                0x8D7C
#define GL_RGB8UI                                 0x8D7D
#define GL_RGBA32I                                0x8D82
#define GL_RGB32I                                 0x8D83
#define GL_RGBA16I                                0x8D88
#define GL_RGB16I                                 0x8D89
#define GL_RGBA8I                                 0x8D8E
#define GL_RGB8I                                  0x8D8F
#define GL_RED_INTEGER                            0x8D94
#define GL_GREEN_INTEGER                          0x8D95
#define GL_BLUE_INTEGER                           0x8D96
#define GL_RGB_INTEGER                            0x8D98
#define GL_RGBA_INTEGER                           0x8D99
#define GL_BGR_INTEGER                            0x8D9A
#define GL_BGRA_INTEGER                           0x8D9B
#define GL_SAMPLER_1D_ARRAY                       0x8DC0
#define GL_SAMPLER_2D_ARRAY                       0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW                0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW                0x8DC4
#define GL_SAMPLER_CUBE_SHADOW                    0x8DC5
#define GL_UNSIGNED_INT_VEC2                      0x8DC6
#define GL_UNSIGNED_INT_VEC3                      0x8DC7
#define GL_UNSIGNED_INT_VEC4                      0x8DC8
#define GL_INT_SAMPLER_1D                         0x8DC9
#define GL_INT_SAMPLER_2D                         0x8DCA
#define GL_INT_SAMPLER_3D                         0x8DCB
#define GL_INT_SAMPLER_CUBE                       0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY                   0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY                   0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D                0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D                0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D                0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE              0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY          0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY          0x8DD7
#define GL_QUERY_WAIT                             0x8E13
#define GL_QUERY_NO_WAIT                          0x8E14
#define GL_QUERY_BY_REGION_WAIT                   0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT                0x8E16
#define GL_BUFFER_ACCESS_FLAGS                    0x911F
#define GL_BUFFER_MAP_LENGTH                      0x9120
#define GL_BUFFER_MAP_OFFSET                      0x9121
#define GL_DEPTH_COMPONENT32F                     0x8CAC
#define GL_DEPTH32F_STENCIL8                      0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV         0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION          0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING  0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE  0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE        0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE      0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE       0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE      0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE      0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE    0x8217
#define GL_FRAMEBUFFER_DEFAULT                    0x8218
#define GL_FRAMEBUFFER_UNDEFINED                  0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT               0x821A
#define GL_MAX_RENDERBUFFER_SIZE                  0x84E8
#define GL_DEPTH_STENCIL                          0x84F9
#define GL_UNSIGNED_INT_24_8                      0x84FA
#define GL_DEPTH24_STENCIL8                       0x88F0
#define GL_TEXTURE_STENCIL_SIZE                   0x88F1
#define GL_TEXTURE_RED_TYPE                       0x8C10
#define GL_TEXTURE_GREEN_TYPE                     0x8C11
#define GL_TEXTURE_BLUE_TYPE                      0x8C12
#define GL_TEXTURE_ALPHA_TYPE                     0x8C13
#define GL_TEXTURE_DEPTH_TYPE                     0x8C16
#define GL_UNSIGNED_NORMALIZED                    0x8C17
#define GL_FRAMEBUFFER_BINDING                    0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING               0x8CA6
#define GL_RENDERBUFFER_BINDING                   0x8CA7
#define GL_READ_FRAMEBUFFER                       0x8CA8
#define GL_DRAW_FRAMEBUFFER                       0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING               0x8CAA
#define GL_RENDERBUFFER_SAMPLES                   0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE     0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME     0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL   0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER   0x8CD4
#define GL_FRAMEBUFFER_COMPLETE                   0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT      0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER     0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER     0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED                0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS                  0x8CDF
#define GL_COLOR_ATTACHMENT0                      0x8CE0
#define GL_COLOR_ATTACHMENT1                      0x8CE1
#define GL_COLOR_ATTACHMENT2                      0x8CE2
#define GL_COLOR_ATTACHMENT3                      0x8CE3
#define GL_COLOR_ATTACHMENT4                      0x8CE4
#define GL_COLOR_ATTACHMENT5                      0x8CE5
#define GL_COLOR_ATTACHMENT6                      0x8CE6
#define GL_COLOR_ATTACHMENT7                      0x8CE7
#define GL_COLOR_ATTACHMENT8                      0x8CE8
#define GL_COLOR_ATTACHMENT9                      0x8CE9
#define GL_COLOR_ATTACHMENT10                     0x8CEA
#define GL_COLOR_ATTACHMENT11                     0x8CEB
#define GL_COLOR_ATTACHMENT12                     0x8CEC
#define GL_COLOR_ATTACHMENT13                     0x8CED
#define GL_COLOR_ATTACHMENT14                     0x8CEE
#define GL_COLOR_ATTACHMENT15                     0x8CEF
#define GL_COLOR_ATTACHMENT16                     0x8CF0
#define GL_COLOR_ATTACHMENT17                     0x8CF1
#define GL_COLOR_ATTACHMENT18                     0x8CF2
#define GL_COLOR_ATTACHMENT19                     0x8CF3
#define GL_COLOR_ATTACHMENT20                     0x8CF4
#define GL_COLOR_ATTACHMENT21                     0x8CF5
#define GL_COLOR_ATTACHMENT22                     0x8CF6
#define GL_COLOR_ATTACHMENT23                     0x8CF7
#define GL_COLOR_ATTACHMENT24                     0x8CF8
#define GL_COLOR_ATTACHMENT25                     0x8CF9
#define GL_COLOR_ATTACHMENT26                     0x8CFA
#define GL_COLOR_ATTACHMENT27                     0x8CFB
#define GL_COLOR_ATTACHMENT28                     0x8CFC
#define GL_COLOR_ATTACHMENT29                     0x8CFD
#define GL_COLOR_ATTACHMENT30                     0x8CFE
#define GL_COLOR_ATTACHMENT31                     0x8CFF
#define GL_DEPTH_ATTACHMENT                       0x8D00
#define GL_STENCIL_ATTACHMENT                     0x8D20
#define GL_FRAMEBUFFER                            0x8D40
#define GL_RENDERBUFFER                           0x8D41
#define GL_RENDERBUFFER_WIDTH                     0x8D42
#define GL_RENDERBUFFER_HEIGHT                    0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT           0x8D44
#define GL_STENCIL_INDEX1                         0x8D46
#define GL_STENCIL_INDEX4                         0x8D47
#define GL_STENCIL_INDEX8                         0x8D48
#define GL_STENCIL_INDEX16                        0x8D49
#define GL_RENDERBUFFER_RED_SIZE                  0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE              0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE     0x8D56
#define GL_MAX_SAMPLES                            0x8D57
#define GL_FRAMEBUFFER_SRGB                       0x8DB9
#define GL_HALF_FLOAT                             0x140B
#define GL_MAP_READ_BIT                           0x0001
#define GL_MAP_WRITE_BIT                          0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT               0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT              0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                 0x0020
#define GL_COMPRESSED_RED_RGTC1                   0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1            0x8DBC
#define GL_COMPRESSED_RG_RGTC2                    0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2             0x8DBE
#define GL_RG                                     0x8227
#define GL_RG_INTEGER                             0x8228
#define GL_R8                                     0x8229
#define GL_R16                                    0x822A
#define GL_RG8                                    0x822B
#define GL_RG16                                   0x822C
#define GL_R16F                                   0x822D
#define GL_R32F                                   0x822E
#define GL_RG16F                                  0x822F
#define GL_RG32F                                  0x8230
#define GL_R8I                                    0x8231
#define GL_R8UI                                   0x8232
#define GL_R16I                                   0x8233
#define GL_R16UI                                  0x8234
#define GL_R32I                                   0x8235
#define GL_R32UI                                  0x8236
#define GL_RG8I                                   0x8237
#define GL_RG8UI                                  0x8238
#define GL_RG16I                                  0x8239
#define GL_RG16UI                                 0x823A
#define GL_RG32I                                  0x823B
#define GL_RG32UI                                 0x823C
#define GL_VERTEX_ARRAY_BINDING                   0x85B5
#endif


typedef long long    GLsizeiptr;
typedef char GLchar;

#define FUNCTION_PTR(function)\
inline PFN_##function function;

typedef const GLubyte* (*PFN_glGetStringi)(GLenum name, GLuint index);
typedef void (*DEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam);
typedef void (*PFN_glDebugMessageCallback)(DEBUGPROC callback, const void* userParam);
typedef void (*PFN_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (*PFN_glGenBuffers) (GLsizei n, GLuint* buffers);
typedef void (*PFN_glBindBuffer) (GLenum target, GLuint buffer);
typedef void (*PFN_glBufferData) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef GLuint(*PFN_glCreateShader) (GLenum type);
typedef void  (*PFN_glShaderSource) (GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
typedef void (*PFN_glLinkProgram) (GLuint program);
typedef void (*PFN_glUseProgram) (GLuint program);
typedef void (*PFN_glCompileShader) (GLuint shader);
typedef void (*PFN_glGetShaderiv) (GLuint shader, GLenum pname, GLint* params);
typedef void (*PFN_glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef GLuint(*PFN_glCreateProgram) (void);
typedef void (*PFN_glAttachShader) (GLuint program, GLuint shader);
typedef void (*PFN_glDeleteShader) (GLuint shader);
typedef void (*PFN_glGetProgramiv) (GLuint program, GLenum pname, GLint* params);
typedef void (*PFN_glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (*PFN_glDeleteProgram) (GLuint program);
typedef void (*PFN_glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void (*PFN_glDisableVertexAttribArray) (GLuint index);
typedef void (*PFN_glEnableVertexAttribArray) (GLuint index);
typedef void (*PFN_glGenVertexArrays) (GLsizei n, GLuint* arrays);
typedef void (*PFN_glBindVertexArray) (GLuint array);
typedef void (*PFN_glDeleteVertexArrays) (GLsizei n, const GLuint* arrays);
typedef void (*PFN_glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (*PFN_glCreateBuffers)(GLsizei n, GLuint* buffers);
typedef void (*PFN_glDeleteBuffers)(GLsizei n, const GLuint* buffers);
typedef void (*PFN_glCreateVertexArrays)(GLsizei n, GLuint* arrays);
typedef void (*PFN_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef GLint (*PFN_glGetUniformLocation)(GLuint program, const GLchar* name);
typedef void  (*PFN_glUniform1i)(GLint location, GLint v0);
typedef void (*PFN_glUniform1f) (GLint location, GLfloat v0);
typedef void  (*PFN_glUniform2fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void  (*PFN_glUniform3fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFN_glUniform4fv)(GLint location, GLsizei count, const GLfloat* value);
typedef void (*PFN_glActiveTexture)(GLenum texture);
typedef void (*PFN_glGenerateMipmap)(GLenum target);
typedef void (*PFN_glGenFramebuffers)(GLsizei n, GLuint* framebuffers);
typedef GLenum (*PFN_glCheckFramebufferStatus)(GLenum target);
typedef void (*PFN_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFN_glBindFramebuffer)(GLenum target, GLuint framebuffer);
typedef void (*PFN_glDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers);
typedef void (*PFN_glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);



FUNCTION_PTR(glGetStringi);
FUNCTION_PTR(glDebugMessageCallback);
FUNCTION_PTR(glDebugMessageControl);
FUNCTION_PTR(glGenBuffers);
FUNCTION_PTR(glBindBuffer);
FUNCTION_PTR(glBufferData);
FUNCTION_PTR(glCreateShader);
FUNCTION_PTR(glLinkProgram);
FUNCTION_PTR(glShaderSource);
FUNCTION_PTR(glUseProgram);
FUNCTION_PTR(glCompileShader);
FUNCTION_PTR(glGetShaderiv);
FUNCTION_PTR(glGetShaderInfoLog);
FUNCTION_PTR(glCreateProgram);
FUNCTION_PTR(glAttachShader);
FUNCTION_PTR(glDeleteShader);
FUNCTION_PTR(glGetProgramiv);
FUNCTION_PTR(glGetProgramInfoLog);
FUNCTION_PTR(glDeleteProgram);
FUNCTION_PTR(glVertexAttribPointer);
FUNCTION_PTR(glDisableVertexAttribArray);
FUNCTION_PTR(glEnableVertexAttribArray);
FUNCTION_PTR(glGenVertexArrays);
FUNCTION_PTR(glBindVertexArray);
FUNCTION_PTR(glDeleteVertexArrays);
FUNCTION_PTR(glDrawArraysInstanced);
FUNCTION_PTR(glCreateBuffers);
FUNCTION_PTR(glDeleteBuffers);
FUNCTION_PTR(glCreateVertexArrays);
FUNCTION_PTR(glGetUniformLocation);
FUNCTION_PTR(glUniformMatrix4fv);
FUNCTION_PTR(glUniform1i);
FUNCTION_PTR(glUniform1f);
FUNCTION_PTR(glUniform2fv);
FUNCTION_PTR(glUniform3fv);
FUNCTION_PTR(glUniform4fv);
FUNCTION_PTR(glActiveTexture);
FUNCTION_PTR(glGenerateMipmap);
FUNCTION_PTR(glGenFramebuffers);
FUNCTION_PTR(glCheckFramebufferStatus);
FUNCTION_PTR(glFramebufferTexture2D);
FUNCTION_PTR(glBindFramebuffer);
FUNCTION_PTR(glDeleteFramebuffers);
FUNCTION_PTR(glCopyImageSubData);