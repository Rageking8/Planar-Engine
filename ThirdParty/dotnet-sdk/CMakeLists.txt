include(ListUtils)

message(STATUS "Fetching .NET SDK")

FetchContent_MakeAvailable(dotnet-sdk)

set(ARCHIVE_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/DotnetSDK)

set(ARCHIVE_CONTENTS_HOST
    host

    dotnet.exe
)
set(ARCHIVE_CONTENTS_SHARED
    shared/Microsoft.NETCore.App
)
set(ARCHIVE_CONTENTS_SDK_80300
    cs
    Current
    de
    es
    fr
    it
    ja
    ko
    pl
    pt-BR
    ref
    Roslyn
    ru
    runtimes
    SdkResolvers
    Sdks
    tr
    trustedroots
    zh-Hans
    zh-Hant

    .toolsetversion
    .version
    datacollector.deps.json
    datacollector.dll
    datacollector.dll.config
    datacollector.runtimeconfig.json
    dotnet.deps.json
    dotnet.dll
    dotnet.runtimeconfig.json
    KnownWorkloadManifests.txt
    Microsoft.Build.dll
    Microsoft.Build.Framework.dll
    Microsoft.Build.NuGetSdkResolver.dll
    Microsoft.Build.Tasks.Core.dll
    Microsoft.Build.Utilities.Core.dll
    Microsoft.Common.CurrentVersion.targets
    Microsoft.Common.overridetasks
    Microsoft.Common.targets
    Microsoft.Common.tasks
    Microsoft.CSharp.CurrentVersion.targets
    Microsoft.CSharp.targets
    Microsoft.Deployment.DotNet.Releases.dll
    Microsoft.DotNet.Cli.Utils.dll
    Microsoft.DotNet.Configurer.dll
    Microsoft.DotNet.InternalAbstractions.dll
    Microsoft.DotNet.TemplateLocator.dll
    Microsoft.Extensions.DependencyModel.dll
    Microsoft.Extensions.Logging.Abstractions.dll
    Microsoft.Managed.After.targets
    Microsoft.Managed.Before.targets
    Microsoft.NET.HostModel.dll
    Microsoft.NET.props
    Microsoft.NET.Sdk.WorkloadManifestReader.dll
    Microsoft.NET.Sdk.WorkloadMSBuildSdkResolver.dll
    Microsoft.NET.StringTools.dll
    Microsoft.NETCoreSdk.BundledVersions.props
    Microsoft.TemplateEngine.Abstractions.dll
    Microsoft.TemplateEngine.Cli.dll
    Microsoft.TemplateEngine.Edge.dll
    Microsoft.TemplateSearch.Common.dll
    minimumMSBuildVersion
    MSBuild.deps.json
    MSBuild.dll
    MSBuild.runtimeconfig.json
    NETCoreSdkRuntimeIdentifierChain.txt
    Newtonsoft.Json.dll
    NuGet.Build.Tasks.Console.dll
    NuGet.Build.Tasks.Console.runtimeconfig.json
    NuGet.Build.Tasks.dll
    NuGet.CommandLine.XPlat.deps.json
    NuGet.CommandLine.XPlat.dll
    NuGet.CommandLine.XPlat.runtimeconfig.json
    NuGet.Commands.dll
    NuGet.Common.dll
    NuGet.Configuration.dll
    NuGet.Credentials.dll
    NuGet.DependencyResolver.Core.dll
    NuGet.Frameworks.dll
    NuGet.LibraryModel.dll
    NuGet.Packaging.Core.dll
    NuGet.Packaging.dll
    NuGet.ProjectModel.dll
    NuGet.props
    NuGet.Protocol.dll
    NuGet.RestoreEx.targets
    NuGet.targets
    NuGet.Versioning.dll
    PortableRuntimeIdentifierGraph.json
    RuntimeIdentifierGraph.json
    SDKPrecomputedAssemblyReferences.cache
    System.CodeDom.dll
    System.CommandLine.dll
    System.ComponentModel.Composition.dll
    System.Configuration.ConfigurationManager.dll
    System.Diagnostics.EventLog.dll
    System.Reflection.MetadataLoadContext.dll
    System.Resources.Extensions.dll
    System.Security.Cryptography.Pkcs.dll
    System.Security.Cryptography.ProtectedData.dll
    System.Security.Cryptography.Xml.dll
    System.ServiceProcess.ServiceController.dll
    testhost.deps.json
    testhost.dll
    testhost-1.0.runtimeconfig.json
    testhost-1.1.runtimeconfig.json
    testhost-2.0.runtimeconfig.json
    testhost-2.1.runtimeconfig.json
    testhost-3.0.runtimeconfig.json
    testhost-3.1.runtimeconfig.json
    testhost-5.0.runtimeconfig.json
    testhost-6.0.runtimeconfig.json
    testhost-7.0.runtimeconfig.json
    testhost-8.0.runtimeconfig.json
    testhost-latest.runtimeconfig.json
    vstest.console.deps.json
    vstest.console.dll
    vstest.console.dll.config
    vstest.console.runtimeconfig.json
)

prepend_lists(${dotnet-sdk_SOURCE_DIR}/
    ARCHIVE_CONTENTS_HOST ARCHIVE_CONTENTS_SHARED
)
PREPEND_LISTS(${dotnet-sdk_SOURCE_DIR}/sdk/8.0.300/
    ARCHIVE_CONTENTS_SDK_80300
)

set(ARCHIVE_DESTINATION
    ${CMAKE_BINARY_DIR}/Asset/dotnet_sdk.zip
)

if(NOT EXISTS ${ARCHIVE_DESTINATION})
    file(COPY ${ARCHIVE_CONTENTS_HOST} DESTINATION
        ${ARCHIVE_WORKING_DIRECTORY}
    )
    file(COPY ${ARCHIVE_CONTENTS_SHARED} DESTINATION
        ${ARCHIVE_WORKING_DIRECTORY}/shared
    )
    file(COPY ${ARCHIVE_CONTENTS_SDK_80300} DESTINATION
        ${ARCHIVE_WORKING_DIRECTORY}/sdk/8.0.300
    )

    file(WRITE ${ARCHIVE_DESTINATION} "")
    file(ARCHIVE_CREATE OUTPUT
        ${ARCHIVE_DESTINATION} PATHS
        ${ARCHIVE_WORKING_DIRECTORY} FORMAT zip
    )
endif()
