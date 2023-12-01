<!-- authorities-search.inc -->

[% BLOCK orderby %]
 <div>
 <label class="control-label">
 Order by

 <select name="orderby" class="form-control">
 [% IF ( orderby == 'HeadingAsc' ) %]
 <option value="HeadingAsc" selected="selected">Đề mục A-Z</option>
 [% ELSE %]
 <option value="HeadingAsc">Đề mục A-Z</option>
 [% END %]
 [% IF ( orderby == 'HeadingDsc' ) %]
 <option value="HeadingDsc" selected="selected">Đề mục Z-A</option>
 [% ELSE %]
 <option value="HeadingDsc">Đề mục Z-A</option>
 [% END %]
 [% IF ( orderby == '' && op ) %]
 <option value="" selected="selected">Bất kỳ</option>
 [% ELSE %]
 <option value="">Bất kỳ</option>
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% BLOCK operator %]
 <div>
 <label class="control-label">
 Operator

 <select name="operator" class="form-control">
 [% IF ( operator == 'contains' ) %]
 <option value="contains" selected="selected">có chứa</option>
 [% ELSE %]
 <option value="contains">có chứa</option>
 [% END %]
 [% IF ( operator == 'start' ) %]
 <option value="start" selected="selected">bắt đầu với</option>
 [% ELSE %]
 <option value="start">bắt đầu với</option>
 [% END %]
 [% IF ( operator == 'exact' ) %]
 <option value="exact" selected="selected">chính xác là</option>
 [% ELSE %]
 <option value="exact">chính xác là</option>
 [% END %]
 </select>
 </label>
 </div>
[% END %]

[% BLOCK authtype %]
 <div>
 <label>
 Authority type
 <select name="authtypecode" class="form-control">
 [% IF (marcflavour == 'UNIMARC' ) %]<option value="">Tất cả kiểu dữ liệu kiểm soát</option>[% END %]
 [% FOREACH authority_type IN authority_types %]
 [% IF authority_type.authtypecode == authtypecode %]
 <option value="[% authority_type.authtypecode | html %]" selected="selected">[% authority_type.authtypetext | html %]</option>
 [% ELSE %]
 <option value="[% authority_type.authtypecode | html %]">[% authority_type.authtypetext | html %]</option>
 [% END %]
 [% END %]
 </select>
 </label>
 </div>
[% END %]

<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="mainmain_heading" role="tabpanel" class="tab-pane active">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label">Search main heading ($a only)</label>
 </div>

 <div class="form-content">
 <input id="value_mainentry" class="form-control head-searchbox" type="text" name="value" value="[% value | html %]" placeholder="Search main heading ($a only)" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="main_heading" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />

 <div class="form-title">
 <label class="control-label">Tìm đề mục chính</label>
 </div>

 <div class="form-content">
 <input class="form-control head-searchbox" id="value_mainheading" name="value" placeholder="Tìm đề mục chính" type="text" value="[% value | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="matchheading_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="match" />

 <div class="form-title">
 <label class="control-label">Tìm kiếm tất cả đề mục</label>
 </div>

 <div class="form-content">
 <input id="value_matchheading" class="form-control head-searchbox" type="text" name="value" value="[% value | html %]" placeholder="Search any heading" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 <div id="entire_record" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/authorities/authorities-home.pl" method="get">
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />

 <div class="form-title">
 <label class="control-label">Search entire record</label>
 </div>

 <div class="form-content">
 <input id="value_anywhere" class="form-control head-searchbox" type="text" name="value" value="[% value | html %]" placeholder="Search any authority field" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <span class="form-extra-content">
 [% INCLUDE authtype %]
 [% INCLUDE operator %]
 [% INCLUDE orderby %]
 </span>
 </form>
 </div>

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a title="Search main heading ($a only)" href="#mainmain_heading" aria-controls="mainmain_heading" role="tab"  aria-expanded="true" data-toggle="tab" class="keep_text"><i style="font-weight:bold">$a</i> <span class="tab-title">Main heading ($a only)</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="main_heading" class="keep_text" data-toggle="tab" href="#main_heading" role="tab" title="Tìm đề mục chính"><i class="fa fa-header"></i> <span class="tab-title">Main heading</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="matchheading_search" class="keep_text" data-toggle="tab" href="#matchheading_search" role="tab" title="Tìm kiếm tất cả đề mục"><i class="fa fa-align-center"></i> <span class="tab-title">All headings</span></a>
 </li>
 <li role="presentation">
 <a title="Search entire record" href="#entire_record" aria-controls="entire_record" role="tab" data-toggle="tab" class="keep_text"><i class="fa fa-folder-open-o"></i> <span class="tab-title">Entire record</span></a>
 </li>
 <li role="presentation">
 </ul>
</div><!-- /#header_search -->
<!-- /authorities-search.inc -->
