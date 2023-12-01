[% USE Koha %]
[% PROCESS 'form-blocks.inc' %]

<div id="toolbar" class="btn-toolbar">
 <div class="btn-group"><a href="#" id="clear" class="btn btn-default btn-sm"><i class="fa fa-trash"></i> Xóa trường</a></div>
 <div class="btn-group"><a href="#" id="createnew" class="btn btn-default btn-sm"><i class="fa fa-plus"></i> Tạo dữ liệu kiểm soát</a></div>
</div>
<form name="f" method="get" action="auth_finder.pl">
 <input type="hidden" name="source" value="[% source | html %]" />
 <input type="hidden" name="op" value="do_search" />
 <input type="hidden" name="type" value="intranet" />
 <input type="hidden" name="index" value="[% index | html %]" />
 <fieldset class="rows"><legend>Tùy chọn tìm kiếm</legend>
 <ol><li>
 <span class="label">Kiểu dữ liệu kiểm soát: </span>
 [% authtypecode | html %]
 <input type="hidden" name="authtypecode" value="[% authtypecode | html %]" />
 </li>
 <li>
 <label for="mainmainentry">Search main heading ($a only): </label>
 <input type="hidden" name="marclist" value="mainmainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainmainentry">
 [% IF ( operator_mainstr == 'contains' ) %]
 <option value="contains" selected="selected">có chứa</option>
 [% ELSE %]
 <option value="contains">có chứa</option>
 [% END %]
 [% IF ( operator_mainstr == 'start' ) %]
 <option value="start" selected="selected">bắt đầu với</option>
 [% ELSE %]
 <option value="start">bắt đầu với</option>
 [% END %]
 [% IF ( operator_mainstr == 'exact' ) %]
 <option value="exact" selected="selected">chính xác là</option>
 [% ELSE %]
 <option value="exact">chính xác là</option>
 [% END %]
 </select>
 <input id="value_mainstr" style="width:400px;" type="text" name="value_mainstr" value="[% value_mainstr | html %]" />
 <div id="yvaluecontainermainmainentry"></div>
 </li>

 <li>
 <label for="mainentry">Search main heading: </label>
 <input type="hidden" name="marclist" value="mainentry" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="mainentry">
 [% IF ( operator_main == 'contains' ) %]
 <option value="contains" selected="selected">có chứa</option>
 [% ELSE %]
 <option value="contains">có chứa</option>
 [% END %]
 [% IF ( operator_main == 'start' ) %]
 <option value="start" selected="selected">bắt đầu với</option>
 [% ELSE %]
 <option value="start">bắt đầu với</option>
 [% END %]
 [% IF ( operator_main == 'exact' ) %]
 <option value="exact" selected="selected">chính xác là</option>
 [% ELSE %]
 <option value="exact">chính xác là</option>
 [% END %]
 </select>
 <input id="value_main" style="width:400px;" type="text" name="value_main" value="[% value_main | html %]" />
 <div id="yvaluecontainermainentry"></div>
 </li>
 <li>
 <label for="marclistheading">Search all headings: </label>
 <input type="hidden" name="marclist" value="match" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistheading">
 [% IF ( operator_match == 'contains' ) %]
 <option value="contains" selected="selected">có chứa</option>
 [% ELSE %]
 <option value="contains">có chứa</option>
 [% END %]
 [% IF ( operator_match == 'start' ) %]
 <option value="start" selected="selected">bắt đầu với</option>
 [% ELSE %]
 <option value="start">bắt đầu với</option>
 [% END %]
 [% IF ( operator_match == 'exact' ) %]
 <option value="exact" selected="selected">chính xác là</option>
 [% ELSE %]
 <option value="exact">chính xác là</option>
 [% END %]
 </select>
 <input type="text" name="value_match" value="[% value_match | html %]" />
 </li>
 <li>
 <label for="marclistanywhere">Search entire record: </label>
 <input type="hidden" name="marclist" value="all" />
 <input type="hidden" name="and_or" value="and" />
 <input type="hidden" name="excluding" value="" />
 <select name="operator" id="marclistanywhere">
 [% IF ( operator_any == 'contains' ) %]
 <option value="contains" selected="selected">có chứa</option>
 [% ELSE %]
 <option value="contains">có chứa</option>
 [% END %]
 [% IF ( operator_any == 'start' ) %]
 <option value="start" selected="selected">bắt đầu với</option>
 [% ELSE %]
 <option value="start">bắt đầu với</option>
 [% END %]
 [% IF ( operator_any == 'exact' ) %]
 <option value="exact" selected="selected">chính xác là</option>
 [% ELSE %]
 <option value="exact">chính xác là</option>
 [% END %]
 </select>
 <input id="value_any" style="width:400px;" type="text" name="value_any" value="[% value_any | html %]" />
 <div id="yvaluecontainermarclist"></div>
 </li>
 <li>
 <label for="orderby">Sắp xếp theo: </label>
 <select name="orderby" id="orderby">
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
 </li></ol></fieldset>
 [% IF source == 'auth' %]
 <fieldset class="rows"><legend>Thông tin liên quan</legend>
 <ol>
 <li>
 <label for="relationship">Liên quan chi tiết: </label>
 <select name="relationship" id="relationship">
 [% selected=relationship | html %]
 [% PROCESS selectoptionopen value='' %]Không xác định</option>
 [% IF Koha.Preference('marcflavour') == 'MARC21' %]
 [% PROCESS selectoptionopen value='a' %]a - Earlier heading</option>
 [% PROCESS selectoptionopen value='b' %]b - Đề mục sau đó</option>
 [% PROCESS selectoptionopen value='d' %]d - Từ viết tắt</option>
 [% PROCESS selectoptionopen value='f' %]f - Tác phẩm âm nhạc</option>
 [% PROCESS selectoptionopen value='g' %]g - Thuật ngữ rộng hơn</option>
 [% PROCESS selectoptionopen value='h' %]h - Thuật ngữ hẹp hơn</option>
 [% PROCESS selectoptionopen value='i' %]i - Tài liệu tham khảo trong trường con $i</option>
 [% PROCESS selectoptionopen value='n' %]n - Không áp dụng</option>
 [% PROCESS selectoptionopen value='r' %]r - Chỉ định liên quan trong $i hoặc $4</option>
 [% PROCESS selectoptionopen value='t' %]t - Trực tiếp trong dữ liệu gốc</option>
 [% ELSIF Koha.Preference('marcflavour') == 'UNIMARC' %]
 [% PROCESS selectoptionopen value='a' %]a = earlier name</option>
 [% PROCESS selectoptionopen value='b' %]b = later name</option>
 [% PROCESS selectoptionopen value='c' %]c = official name</option>
 [% PROCESS selectoptionopen value='d' %]d = acronym / initial / abbreviation</option>
 [% PROCESS selectoptionopen value='e' %]e = pseudonym</option>
 [% PROCESS selectoptionopen value='f' %]f = real name</option>
 [% PROCESS selectoptionopen value='g' %]g = broader term or name</option>
 [% PROCESS selectoptionopen value='h' %]h = narrower term or name</option>
 [% PROCESS selectoptionopen value='i' %]i = name in religion</option>
 [% PROCESS selectoptionopen value='j' %]j = married name</option>
 [% PROCESS selectoptionopen value='k' %]k = name before marriage</option>
 [% PROCESS selectoptionopen value='l' %]l = shared pseudonym</option>
 [% PROCESS selectoptionopen value='m' %]m = secular name</option>
 [% PROCESS selectoptionopen value='n' %]n = different rule form of a name</option>
 [% PROCESS selectoptionopen value='o' %]o = attributed name / conventional title of a work</option>
 [% PROCESS selectoptionopen value='x' %]x = not applicable</option>
 [% PROCESS selectoptionopen value='z' %]z = other</option>
 [% END %]
 </select>
 </li>
 </ol>
 </fieldset>
 [% END %]
 <fieldset class="action"> <input class="submit" id="search" type="submit" value="Tìm kiếm" /> <a id="cancel" class="cancel close" href="#">Hủy bỏ</a>
 </fieldset>
</form>
