#
# Manta
# Copyright (c) 2013-2015 Illumina, Inc.
#
# This software is provided under the terms and conditions of the
# Illumina Open Source Software License 1.
#
# You should have received a copy of the Illumina Open Source
# Software License 1 along with this program. If not, see
# <https://github.com/sequencing/licenses/>
#

"""
This consolidates build-time config data such as git status
and build date. This is in contrast to cmake configuration-time
config data like relative paths and library/header availability.
"""

workflowVersion="@WORKFLOW_VERSION@"
buildTime="@BUILD_TIME@"