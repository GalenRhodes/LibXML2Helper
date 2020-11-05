/************************************************************************//**
 *     PROJECT: LibXML2Helper
 *    FILENAME: LibXML2Helper.h
 *         IDE: AppCode
 *      AUTHOR: Galen Rhodes
 *        DATE: 11/5/20
 *
 * Copyright © 2020 Project Galen. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *//************************************************************************/

#ifndef ____LibXML2Helper_h____
#define ____LibXML2Helper_h____

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libxml/parser.h>

__BEGIN_DECLS

#define PG_EXPORT extern __attribute__((__visibility__("default")))

typedef void (*warningSAXSwiftFunc)(void *ctx, const char *msg);

typedef void (*errorSAXSwiftFunc)(void *ctx, const char *msg);

typedef void (*fatalErrorSAXSwiftFunc)(void *ctx, const char *msg);

typedef struct _LibXmlSAXHandler {
    xmlSAXHandler          saxHandler;
    warningSAXSwiftFunc    warningSaxSwiftFunc;
    errorSAXSwiftFunc      errorSaxSwiftFunc;
    fatalErrorSAXSwiftFunc fatalErrorSaxSwiftFunc;
}            LibXmlSAXHandler;

typedef struct _LibXmlSAXUserData {
    LibXmlSAXHandler handler;
    void *parser;
} LibXmlSAXUserData;

PG_EXPORT void addErrorHandlers(LibXmlSAXHandler *handler);

__END_DECLS

#endif // ____LibXML2Helper_h____
